
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter_lake/FlutterWeather/WeatherData.dart';

class Weather extends StatelessWidget{
  @override
  Widget build(BuildContext context) {
    return new MaterialApp(
      title: 'Flutter Weather',
      theme: new ThemeData(
        primarySwatch: Colors.blue
      ),
      home: new Center(
        child: new WeatherPage(),
      ),
    );
  }
}

class WeatherPage extends StatefulWidget{
  WeatherPage({Key key}):super(key:key);

  _WeatherPage createState() => _WeatherPage();
}

class _WeatherPage extends State<WeatherPage>{


  WeatherData weather = WeatherData.empty();

  WeatherState(){
    _getWeather();
  }

  void _getWeather() async{
    WeatherData data = await _fetchWeather();
    setState((){
      weather = data;
    });
  }

  Future<WeatherData> _fetchWeather() async{
    final response = await http.get(
        'https://free-api.heweather.com/s6/weather/now?location=邢台&key=551f547c64b24816acfed8471215cd0e'
    );
    if(response.statusCode == 200){
      return WeatherData.fromJson(json.decode(response.body));
    }else{
      return WeatherData.empty();
    }
  }


  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text('Flutter Weather'),
      ),
      body: new Stack(
        fit: StackFit.expand,
        children: <Widget>[
          new Image.asset("images/weather_bg.jpg",fit: BoxFit.fill),
          new Column(
            mainAxisAlignment: MainAxisAlignment.start, //垂直布局
            crossAxisAlignment: CrossAxisAlignment.center,  //水平布局
            children: <Widget>[
              new Container(
                width: double.infinity,
                margin: EdgeInsets.only(top: 45.0),
                child: new Text(
                  "邢台市",
                  textAlign: TextAlign.center,
                  style: new TextStyle(
                    color: Colors.white,
                    fontSize: 30.0,
                  ),
                ),
              ),
              new Container(
                width: double.infinity,
                margin: EdgeInsets.only(top: 60.0),
                child: new Column(
                  children: <Widget>[
                    new Text(
                      weather?.tmp,
                      style: new TextStyle(
                        color: Colors.white,
                        fontSize: 80.0
                      ),
                    ),
                    new Text(
                      weather?.cond,
                      style: new TextStyle(
                        color: Colors.white,
                        fontSize: 45.0,
                      ),
                    ),
                    new Text(
                      weather?.hum,
                      style: new TextStyle(
                        color: Colors.white,
                        fontSize: 30.0,
                      ),
                    )
                  ],
                ),
              )
            ],
          )
        ],
      )
    );
  }
}