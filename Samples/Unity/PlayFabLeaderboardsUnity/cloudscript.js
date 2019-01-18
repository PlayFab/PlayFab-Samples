handlers.updateStatistic = function (args, context) {
  var event = context.playStreamEvent;

  if(event != null) {
    var request = {
      PlayFabId: currentPlayerId,
      Statistics: [{
        StatisticName: event.stat_name,
        Value: event.value
      }]
    };

    server.UpdatePlayerStatistics(request);
  }    
};

handlers.updateStatistics = function (args, context) {
  var event = context.playStreamEvent;

  if(event != null) {
    var stats = event.stats;
    var statArray = [];
    
    for(var key in stats) {
    	var value = stats[key];  
    	statArray.push({StatisticName: key, Value: value});
	}
    
    var request = {
      PlayFabId: currentPlayerId, 
      Statistics: statArray
    };
    
    server.UpdatePlayerStatistics(request);
  }    
};
