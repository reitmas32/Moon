import 'package:flutter/material.dart';

import 'package:http/http.dart' as http;
import 'dart:io';

import 'package:moon_docs/controllers/page_controller.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      routes: RoutePagesController.getRoutes(context),
      initialRoute: '/Home',
    );
  }
}