import 'package:flutter/material.dart';
import 'package:link/link.dart';
import 'package:flutter_markdown/flutter_markdown.dart';

const String infoMarkdown = '''
Moon es un Game Engine desarrollado por KEGE Studios escrito en C/C++, fue diseñado basado en la Arquitectura ECS y usando algunas funcionalidades del nuevo estándar de C++20.
### Características principales
- Eficiente en el uso de Recursos
- Arquitectura Kernel para el escalamiento e interacción entre los plugins
- Uso de la STL para los contenedores
- Concepts implementados para una mayor seguridad en templates
- Predicción de tipos en tiempo de compilación
- Un Core simple, liviano y libre
- Plugins pequeños y específicos
- Ejemplos para todos los plugins oficiales
- Solo incluyes lo que necesitas
- Independencia de plugins

### Caracteristicas de la versión
- GameContext
- System
- Component
- Entity
- Herramienta de Instalacion y creacion de proyectos
- Uso de la STL para los contenedores
''';

class Home extends StatefulWidget {
  Home({Key key, this.title}) : super(key: key);
  final String title;

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  int _counter = 0;
  ScrollController controller;

  @override
  void initState() {
    this.controller = ScrollController();
    super.initState();
  }

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  void _showErrorSnackBar() {
    Scaffold.of(context).showSnackBar(
      SnackBar(
        content: Text('Oops... the URL couldn\'t be opened!'),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      //appBar: buildAppBarWeb(context),
      body: Padding(
        padding: EdgeInsets.symmetric(
            horizontal: (MediaQuery.of(context).size.width / 8)),
        child: Container(
          color: Colors.grey[50],
          child: ListView(
            children: [
              buildAppBarWeb(context),
              SizedBox(
                height: MediaQuery.of(context).size.height / 4,
              ),
              Center(
                child: Text(
                  'Moon',
                  style: TextStyle(
                    fontSize: 40,
                    color: Colors.blueAccent,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
              SizedBox(
                height: MediaQuery.of(context).size.height / 15,
              ),
              Center(
                child: RichText(
                  text: TextSpan(
                    style: TextStyle(fontSize: 25),
                    children: [
                      TextSpan(text: 'Un '),
                      TextSpan(
                        text: 'Game Engine ',
                        style: TextStyle(
                          color: Colors.blueAccent,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      TextSpan(text: ' desarrollado en  '),
                      TextSpan(
                        text: 'C/C++ ',
                        style: TextStyle(
                          color: Colors.blueAccent,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      TextSpan(text: 'usando la '),
                      TextSpan(
                        text: 'Arquitectura ECS',
                        style: TextStyle(
                          color: Colors.blueAccent,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                    ],
                  ),
                ),
              ),
              SizedBox(
                height: MediaQuery.of(context).size.height / 15,
              ),
              Center(
                child: RaisedButton(
                  onPressed: () {},
                  shape: RoundedRectangleBorder(
                    borderRadius: new BorderRadius.circular(30.0),
                  ),
                  child: Text(
                    'v1.0.0',
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 20,
                    ),
                  ),
                  color: Colors.blueAccent,
                ),
              ),
              SizedBox(
                height: MediaQuery.of(context).size.height / 15,
              ),
              Container(
                height: MediaQuery.of(context).size.height / 1.35,
                padding: EdgeInsets.symmetric(
                    horizontal: (MediaQuery.of(context).size.width / 8)),
                child: Markdown(
                  data: infoMarkdown,
                  selectable: true,
                ),
              ),
            ],
          ),
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: Icon(Icons.add),
      ),
    );
  }

  Container buildAppBarWeb(BuildContext context) {
    return Container(
      color: Colors.grey[50],
      child: Row(
        children: [
          Container(
            child: Expanded(
              child: buildTitle(),
            ),
            width: MediaQuery.of(context).size.width / 10,
          ),
          buildOptionsAppBar(context)
        ],
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
      ),
    );
  }

  Container buildOptionsAppBar(BuildContext context) {
    return Container(
      child: Expanded(
        child: Row(
          children: [
            AppBarButton(
              text: 'Instalación',
              onTap: () {
                print("Instalación");
              },
            ),
            AppBarButton(
              text: 'Manual',
              onTap: () {
                print("Manual");
              },
            ),
            AppBarButton(
              text: 'Plugins',
              onTap: () {
                print("Plugins");
              },
            ),
            AppBarButton(
              text: 'Ejemplos',
              onTap: () {
                print("Ejemplos");
              },
            ),
            buildLinkGithub(),
          ],
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        ),
      ),
      width: (MediaQuery.of(context).size.width / 10) * 6,
    );
  }

  Row buildTitle() {
    return Row(
      children: [
        buildLinkMoon(),
        AppBarButton(
          text: 'Moon',
          onTap: () {
            print("Moon");
          },
        ),
      ],
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
    );
  }

  InkWell buildLinkMoon() {
    return InkWell(
      onTap: () {
        print("Moon Home");
      },
      child: Image.network(
        'https://raw.githubusercontent.com/reitmas32/Moon/master/assets/logo-moon.png',

        height: 50,
        //height: 32,
      ),
    );
  }

  Link buildLinkGithub() {
    return Link(
        child: Image.network(
          'https://image.flaticon.com/icons/png/512/25/25231.png',

          height: 25,
          //height: 32,
        ),
        url: 'https://github.com/reitmas32/Moon',
        onError: () {});
  }
}

class AppBarButton extends StatelessWidget {
  final String text;
  final void Function() onTap;
  const AppBarButton({Key key, this.onTap, this.text}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: this.onTap,
      child: Text(
        this.text,
        style: TextStyle(color: Colors.blueAccent, fontSize: 20),
      ),
    );
  }
}
