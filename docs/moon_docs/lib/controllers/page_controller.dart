import 'package:flutter/material.dart';
import 'package:moon_docs/pages/home_page.dart';

//Pages Widgets

///Metodo que almacena las rutas de la App
class RoutePagesController {
  static Map<String, WidgetBuilder> getRoutes(BuildContext context) {
    return {
      '/Home': (context) => Home(),
    };
  }
}