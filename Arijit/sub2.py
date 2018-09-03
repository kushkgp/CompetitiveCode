from backtester.trading_system_parameters import TradingSystemParameters
from backtester.features.feature import Feature
from datetime import datetime, timedelta
from backtester.dataSource.csv_data_source import CsvDataSource
from problem2_execution_system import Problem2ExecutionSystem
from backtester.trading_system import TradingSystem
from backtester.version import updateCheck
from backtester.constants import *
from backtester.features.feature import Feature
from backtester.logger import *
import pandas as pd
import numpy as np
import sys
from problem2_trading_params import MyTradingParams
from sklearn import linear_model
from sklearn.svm import SVR

## Make your changes to the functions below.
## SPECIFY features you want to use in getInstrumentFeatureConfigDicts() and getMarketFeatureConfigDicts()
## Create your bid and offers using these features in makeMarket()
## SPECIFY any custom features in getCustomFeatures() below
## Don't change any other function
## The toolbox does the rest for you, from downloading and loading data to running backtest


class MyTradingFunctions():

    def __init__(self):  #Put any global variables here
        self.lookback = 1200  ## TODO: max number of historical datapoints you want at any given time
        self.dataSetId = 'QQ4Data'
        self.params = {}

        # for example you can import and store an ML model from scikit learn in this dict
        self.model = {}

        # and set a frequency at which you want to update the model

        self.updateFrequency = 5


    ###########################################
    ## ONLY FILL THE THREE FUNCTIONS BELOW    ##
    ###########################################

    '''
    Specify all Features you want to use by  by creating config dictionaries.
    Create one dictionary per feature and return them in an array.
    Feature config Dictionary have the following keys:
        featureId: a str for the type of feature you want to use
        featureKey: {optional} a str for the key you will use to call this feature
                    If not present, will just use featureId
        params: {optional} A dictionary with which contains other optional params if needed by the feature
    msDict = {'featureKey': 'ms_5',
              'featureId': 'moving_sum',
              'params': {'period': 5,
                         'featureName': 'basis'}}
    return [msDict]
    You can now use this feature by in getPRediction() calling it's featureKey, 'ms_5'
    '''

    def getInstrumentFeatureConfigDicts(self):

    ##############################################################################
    ### TODO 1: FILL THIS FUNCTION TO CREATE DESIRED FEATURES for each symbol. ###
    ### USE TEMPLATE BELOW AS EXAMPLE                                          ###
    ##############################################################################
        ask_mom1Dict = {'featureKey': 'ask_mom_5',
                   'featureId': 'momentum',
                   'params': {'period': 15,
                              'featureName': 'ask'}}
        ask_mom2Dict = {'featureKey': 'ask_mom_10',
                   'featureId': 'momentum',
                   'params': {'period': 20,
                              'featureName': 'ask'}}
        ask_ma1Dict = {'featureKey': 'ask_ma_5',
                   'featureId': 'moving_average',
                   'params': {'period': 5,
                              'featureName': 'ask'}}
        ask_ma2Dict = {'featureKey': 'ask_ma_10',
                   'featureId': 'moving_average',
                   'params': {'period': 10,
                              'featureName': 'ask'}}
        ask_moving20_sdev = {'featureKey': 'ask_moving_sdev',
                  'featureId': 'moving_sdev',
                  'params': {'period': 20,
                             'featureName': 'ask'}}
        ask_rsi_5 = {'featureKey': 'ask_rsi_5',
                  'featureId': 'rsi',
                  'params': {'period': 5,
                             'featureName': 'ask'}}
        ask_moving50_max = {'featureKey': 'ask_moving_max',
                  'featureId': 'moving_max',
                  'params': {'period': 50,
                             'featureName': 'ask'}}
        ask_ema_10 = {'featureKey': 'ask_exponential_moving_average_10',
                  'featureId': 'exponential_moving_average',
                  'params': {'period': 10,
                             'featureName': 'ask'}}
        ask_ema_20 = {'featureKey': 'ask_exponential_moving_average_20',
                  'featureId': 'exponential_moving_average',
                  'params': {'period': 20,
                             'featureName': 'ask'}}
        ask_macd_10_10 = {'featureKey': 'ask_macd_10_10',
                  'featureId': 'macd',
                  'params': {'period1': 10,
                     'period2': 10,      
                             'featureName': 'ask'}}
        ask_csm_10 = {'featureKey': 'ask_cross_sectional_momentum_10',
                  'featureId': 'cross_sectional_momentum',
                  'params': {'period': 10,
                             'featureName': 'ask'}}
        ask_bbandlowerDict_30 = {'featureKey': 'ask_bollinger_bands_lower_30',
                     'featureId': 'bollinger_bands_lower',
                     'params': {'period': 30,
                               'featureName': 'ask'}}

        ask_bbandupperDict_30 = {'featureKey': 'ask_bollinger_bands_upper_30',
                     'featureId': 'bollinger_bands_upper',
                     'params': {'period': 30,
                               'featureName': 'ask'}}






        bid_mom1Dict = {'featureKey': 'bid_mom_5',
                       'featureId': 'momentum',
                       'params': {'period': 15,
                              'featureName': 'bid'}}
        bid_mom2Dict = {'featureKey': 'bid_mom_10',
                   'featureId': 'momentum',
                   'params': {'period': 20,
                              'featureName': 'bid'}}
        bid_ma1Dict = {'featureKey': 'bid_ma_5',
                   'featureId': 'moving_average',
                   'params': {'period': 5,
                              'featureName': 'bid'}}
        bid_ma2Dict = {'featureKey': 'bid_ma_10',
                   'featureId': 'moving_average',
                   'params': {'period': 10,
                              'featureName': 'bid'}}
        bid_moving20_sdev = {'featureKey': 'bid_moving_sdev',
                  'featureId': 'moving_sdev',
                  'params': {'period': 20,
                             'featureName': 'bid'}}
        bid_rsi_5 = {'featureKey': 'bid_rsi_5',
                  'featureId': 'rsi',
                  'params': {'period': 5,
                             'featureName': 'bid'}}
        bid_moving50_max = {'featureKey': 'bid_moving_max',
                  'featureId': 'moving_max',
                  'params': {'period': 50,
                             'featureName': 'bid'}}
        bid_ema_10 = {'featureKey': 'bid_exponential_moving_average_10',
                  'featureId': 'exponential_moving_average',
                  'params': {'period': 10,
                             'featureName': 'bid'}}
        bid_ema_20 = {'featureKey': 'bid_exponential_moving_average_20',
                  'featureId': 'exponential_moving_average',
                  'params': {'period': 20,
                             'featureName': 'bid'}}
        bid_macd_10_10 = {'featureKey': 'bid_macd_10_10',
                  'featureId': 'macd',
                  'params': {'period1': 10,
                     'period2': 10,      
                             'featureName': 'bid'}}
        bid_csm_10 = {'featureKey': 'bid_cross_sectional_momentum_10',
                  'featureId': 'cross_sectional_momentum',
                  'params': {'period': 10,
                             'featureName': 'bid'}}
        bid_bbandlowerDict_30 = {'featureKey': 'bid_bollinger_bands_lower_30',
                     'featureId': 'bollinger_bands_lower',
                     'params': {'period': 30,
                               'featureName': 'bid'}}

        bid_bbandupperDict_30 = {'featureKey': 'bid_bollinger_bands_upper_30',
                     'featureId': 'bollinger_bands_upper',
                     'params': {'period': 30,
                               'featureName': 'bid'}}

        return [ask_mom1Dict, ask_mom2Dict, ask_ma1Dict, ask_ma2Dict, ask_moving20_sdev, ask_rsi_5, ask_moving50_max, ask_ema_10,ask_ema_20, ask_macd_10_10, ask_bbandupperDict_30, ask_bbandlowerDict_30,
                bid_mom1Dict, bid_mom2Dict, bid_ma1Dict, bid_ma2Dict, bid_moving20_sdev, bid_rsi_5,bid_moving50_max,bid_ema_10,bid_ema_20, bid_macd_10_10,bid_bbandupperDict_30,bid_bbandlowerDict_30]


    def getModelConfigDicts(self):
        regression_model = {'modelKey': 'linear_regression',
                     'modelId' : 'linear_regression',
                     'params' : {}}

        mlp_regression_model = {'modelKey': 'mlp_regression',
                     'modelId' : 'mlp_regression',
                     'params' : {}}

        classification_model = {'modelKey': 'logistic_regression',
                     'modelId' : 'logistic_regression',
                     'params' : {}}

        mlp_classification_model = {'modelKey': 'mlp_classification',
                     'modelId' : 'mlp_classification',
                     'params' : {}}

        svm_model = {'modelKey': 'svm_model',
                     'modelId' : 'support_vector_machine',
                     'params' : {}}
        return [svm_model, mlp_classification_model, classification_model, mlp_regression_model, regression_model]

    def getMarketFeatureConfigDicts(self):
    ###############################################################################
    ### TODO 2: FILL THIS FUNCTION TO CREATE features that use multiple symbols ###
    ### USE TEMPLATE BELOW AS EXAMPLE                                           ###
    ###############################################################################

        # customFeatureDict = {'featureKey': 'custom_mrkt_feature',
        #                      'featureId': 'my_custom_mrkt_feature',
        #                      'params': {'param1': 'value1'}}
        return []

    '''
    Combine all the features to create the desired market for each symbol.
    'marketSeries' is Pandas Series with symbol as index and tuple of (bid, ask) as values
    We first call the holder for all the instrument features for all symbols as
        lookbackInstrumentFeatures = instrumentManager.getLookbackInstrumentFeatures()
    Then call the dataframe for a feature using its feature_key as
        ms5Data = lookbackInstrumentFeatures.getFeatureDf('ms_5')
    This returns a dataFrame for that feature for ALL symbols for all times upto lookback time
    Now you can call just the last data point for ALL symbols as
        ms5 = ms5Data.iloc[-1]
    You can call last datapoint for one symbol 'ABC' as
        value_for_abs = ms5['ABC']
    Output of the prediction function is used by the toolbox to make further trading decisions and evaluate your score.
    '''

    def makeMarket(self, time, updateNum, instrumentManager, marketSeries):
        # holder for all the instrument features for all instruments
        lookbackInstrumentFeatures = instrumentManager.getLookbackInstrumentFeatures()
        # holder for all the market features
        lookbackMarketFeatures = instrumentManager.getDataDf()

        #############################################################################################
        ###  TODO 3 : FILL THIS FUNCTION TO RETURN A (bid,ask) for each stockID                   ###
        ###  You can use all the features created above and combine then using any logic you like ###
        ###  USE TEMPLATE BELOW AS EXAMPLE                                                        ###
        #############################################################################################

        # Time to start making the market.

        for stockId in self.getSymbolsToTrade():
            
            
            # First we get the bid and ask price series for all stocks
            askPrice = lookbackInstrumentFeatures.getFeatureDf('ask')[stockId]
            bidPrice = lookbackInstrumentFeatures.getFeatureDf('bid')[stockId]

            #creating features table
            ask_features_X = pd.DataFrame(index = askPrice.index, columns =  [])
            bid_features_X = pd.DataFrame(index = askPrice.index, columns =  [])
            spread_value = pd.DataFrame(index = askPrice.index, columns =  [])

            spread_value['spread'] = lookbackInstrumentFeatures.getFeatureDf('ask')[stockId] - lookbackInstrumentFeatures.getFeatureDf('bid')[stockId]

            # This is a way to access the feature df's for every stock
            #ask_features_X['ask_ma_5'] = lookbackInstrumentFeatures.getFeatureDf('ask_ma_5')[stockId]
            #bid_features_X['bid_ma_5'] = lookbackInstrumentFeatures.getFeatureDf('bid_ma_5')[stockId]

            #ask_features_X['ask_ma_10'] = lookbackInstrumentFeatures.getFeatureDf('ask_ma_10')[stockId]
            #bid_features_X['bid_ma_10'] = lookbackInstrumentFeatures.getFeatureDf('bid_ma_10')[stockId]

            #ask_features_X['ask_mom_5'] = lookbackInstrumentFeatures.getFeatureDf('ask_mom_5')[stockId]
            #bid_features_X['bid_mom_5'] = lookbackInstrumentFeatures.getFeatureDf('bid_mom_5')[stockId]

            #ask_features_X['ask_rsi_5'] = lookbackInstrumentFeatures.getFeatureDf('ask_rsi_5')[stockId]
            #bid_features_X['bid_rsi_5'] = lookbackInstrumentFeatures.getFeatureDf('bid_rsi_5')[stockId]

            #ask_features_X['ask_macd_10_10'] = lookbackInstrumentFeatures.getFeatureDf('ask_macd_10_10')[stockId]
            #bid_features_X['bid_macd_10_10'] = lookbackInstrumentFeatures.getFeatureDf('bid_macd_10_10')[stockId]

            #ask_features_X['ask_csm_10'] = lookbackInstrumentFeatures.getFeatureDf('ask_cross_sectional_momentum_10')[stockId]
            #bid_features_X['bid_csm_10'] = lookbackInstrumentFeatures.getFeatureDf('bid_cross_sectional_momentum_10')[stockId]

            ask_features_X['ask_mom_10'] = lookbackInstrumentFeatures.getFeatureDf('ask_mom_10')[stockId]
            bid_features_X['bid_mom_10'] = lookbackInstrumentFeatures.getFeatureDf('bid_mom_10')[stockId]

            ask_features_X['ask_bbandupperDict_30'] = lookbackInstrumentFeatures.getFeatureDf('ask_bollinger_bands_upper_30')[stockId]
            bid_features_X['bid_bbandupperDict_30'] = lookbackInstrumentFeatures.getFeatureDf('bid_bollinger_bands_upper_30')[stockId]

            ask_features_X['ask_bbandlowerDict_30'] = lookbackInstrumentFeatures.getFeatureDf('ask_bollinger_bands_lower_30')[stockId]
            bid_features_X['bid_bbandlowerDict_30'] = lookbackInstrumentFeatures.getFeatureDf('bid_bollinger_bands_lower_30')[stockId]

            ask_features_X['ask_moving20_sdev'] = lookbackInstrumentFeatures.getFeatureDf('ask_moving_sdev')[stockId]
            bid_features_X['bid_moving20_sdev'] = lookbackInstrumentFeatures.getFeatureDf('bid_moving_sdev')[stockId]

            #ask_features_X['ask_moving50_max'] = lookbackInstrumentFeatures.getFeatureDf('ask_moving_max')[stockId]
            #bid_features_X['bid_moving50_max'] = lookbackInstrumentFeatures.getFeatureDf('bid_moving_max')[stockId]

            #ask_features_X['ask_ema_10'] = lookbackInstrumentFeatures.getFeatureDf('ask_exponential_moving_average_10')[stockId]
            #bid_features_X['bid_ema_10'] = lookbackInstrumentFeatures.getFeatureDf('bid_exponential_moving_average_10')[stockId]

            #ask_features_X['ask_ema_20'] = lookbackInstrumentFeatures.getFeatureDf('ask_exponential_moving_average_20')[stockId]
            #bid_features_X['bid_ema_20'] = lookbackInstrumentFeatures.getFeatureDf('bid_exponential_moving_average_20')[stockId]


            model = linear_model.LinearRegression()

            model.fit(ask_features_X, askPrice)
            model.fit(bid_features_X, bidPrice)

            ansBid = model.predict(bid_features_X)[len(model.predict(bid_features_X))-1]
            ansAsk = model.predict(ask_features_X)[len(model.predict(ask_features_X))-1]

            # In this simple case, we are just joining the market at current bid and ask price.
            marketSeries[stockId] = (ansBid, ansAsk)
            
        
        return marketSeries

    ###########################################
    ##         DONOT CHANGE THESE            ##
    ###########################################

    def getSymbolsToTrade(self):
        return ['SIZ','MLQ','MAI','PVV','IPV','DHP','EKA','EYC','YSB','SEP','INS','IIZ','DFY','OAX']

    def getPrediction(self, time, updateNum, instrumentManager,predictions):
        return self.makeMarket(time, updateNum, instrumentManager, predictions)

    def getLookbackSize(self):
        return self.lookback

    def getDataSetId(self):
        return self.dataSetId

    def getTargetVariableKey(self):
        return self.targetVariable

    def setTargetVariableKey(self, targetVariable):
        self.targetVariable = targetVariable

    ######################################################
    ##  TODO: CHANGE ONLY IF YOU HAVE CUSTOM FEATURES  ##
    ######################################################

    def getCustomFeatures(self):
        return {'my_custom_feature_identifier': MyCustomFeatureClassName}

####################################################
##   YOU CAN DEFINE ANY CUSTOM FEATURES HERE      ##
##  If YOU DO, MENTION THEM IN THE FUNCTION ABOVE ##
####################################################
class MyCustomFeatureClassName(Feature):
    ''''
    Custom Feature to implement for instrument. This function would return the value of the feature you want to implement.
    1. create a new class MyCustomFeatureClassName for the feature and implement your logic in the function computeForInstrument() -
    2. modify function getCustomFeatures() to return a dictionary with Id for this class
        (follow formats like {'my_custom_feature_identifier': MyCustomFeatureClassName}.
        Make sure 'my_custom_feature_identifier' doesnt conflict with any of the pre defined feature Ids
        def getCustomFeatures(self):
            return {'my_custom_feature_identifier': MyCustomFeatureClassName}
    3. create a dict for this feature in getInstrumentFeatureConfigDicts() above. Dict format is:
            customFeatureDict = {'featureKey': 'my_custom_feature_key',
                                'featureId': 'my_custom_feature_identifier',
                                'params': {'param1': 'value1'}}
    You can now use this feature by calling it's featureKey, 'my_custom_feature_key' in getPrediction()
    '''
    @classmethod
    def computeForInstrument(cls, updateNum, time, featureParams, featureKey, instrumentManager):
        # Custom parameter which can be used as input to computation of this feature
        param1Value = spread_value['spread']

        # A holder for the all the instrument features
        lookbackInstrumentFeatures = instrumentManager.getLookbackInstrumentFeatures()

        # dataframe for a historical instrument feature (basis in this case). The index is the timestamps
        # atmost upto lookback data points. The columns of this dataframe are the symbols/instrumentIds.
        lookbackInstrumentValue = lookbackInstrumentFeatures.getFeatureDf('ask')
        lookbackInstrumentValue = lookbackInstrumentFeatures.getFeatureDf('bid')

        # The last row of the previous dataframe gives the last calculated value for that feature (basis in this case)
        # This returns a series with symbols/instrumentIds as the index.
        currentValue = lookbackInstrumentValue.iloc[-1]

        if param1Value < 0:
            return currentValue + bid
        else:
            return currentValue


if __name__ == "__main__":
    if updateCheck():
        print('Your version of the auquan toolbox package is old. Please update by running the following command:')
        print('pip install -U auquan_toolbox')
    else:
        print('Loading your config dicts and prediction function')
        tf = MyTradingFunctions()
        print('Loaded config dicts and prediction function, Loading Problem 2 Params')
        tsParams = MyTradingParams(tf)
        print('Loaded Problem 2 Params, Loading Backtester and Data')
        tradingSystem = TradingSystem(tsParams)
        print('Loaded Backtester and Data Loaded, Backtesting')
    # Set onlyAnalyze to True to quickly generate csv files with all the features
    # Set onlyAnalyze to False to run a full backtest
    # Set makeInstrumentCsvs to False to not make instrument specific csvs in runLogs. This improves the performance BY A LOT
tradingSystem.startTrading(onlyAnalyze=False, shouldPlot=True, makeInstrumentCsvs=False)