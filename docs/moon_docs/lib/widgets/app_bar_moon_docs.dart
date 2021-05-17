import 'package:flutter/material.dart';
import 'package:link/link.dart';

class AppBarMoonDocs extends StatefulWidget {
  @override
  _AppBarMoonDocsState createState() => _AppBarMoonDocsState();
}

class _AppBarMoonDocsState extends State<AppBarMoonDocs> {
  @override
  Widget build(BuildContext context) {
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
                Navigator.pushNamed(context, '/Introduction');
              },
            ),
            AppBarButton(
              text: 'Manual',
              onTap: () {
                Navigator.pushNamed(context, '/Manual');
              },
            ),
            AppBarButton(
              text: 'Plugins',
              onTap: () {
                Navigator.pushNamed(context, '/Plugins');
              },
            ),
            AppBarButton(
              text: 'Ejemplos',
              onTap: () {
                Navigator.pushNamed(context, '/Examples');
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
            Navigator.pushNamed(context, '/Home');
          },
        ),
      ],
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
    );
  }

  InkWell buildLinkMoon() {
    return InkWell(
      onTap: () {
        Navigator.pushNamed(context, '/Home');
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
