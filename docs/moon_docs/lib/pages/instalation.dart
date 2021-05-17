import 'package:flutter/material.dart';
import 'package:flutter_markdown/flutter_markdown.dart';
import 'package:moon_docs/markdown/getting-started/instalation.dart';
import 'package:moon_docs/markdown/getting-started/setting-the-environment.dart';
import 'package:moon_docs/widgets/app_bar_moon_docs.dart';

class InstalationPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      //appBar: buildAppBarWeb(context),
      body: Padding(
        padding: EdgeInsets.symmetric(
            horizontal: (MediaQuery.of(context).size.width / 8)),
        child: Container(
          child: ListView(
            children: [
              AppBarMoonDocs(),
              SizedBox(
                height: MediaQuery.of(context).size.height / 10,
              ),
              Container(
                height: MediaQuery.of(context).size.height / 4,
                padding: EdgeInsets.symmetric(
                    horizontal: (MediaQuery.of(context).size.width / 8)),
                child: Markdown(
                  data: getting_started_setting_the_environment_md,
                  selectable: true,
                ),
              ),
              Container(
                height: MediaQuery.of(context).size.height / 2,
                padding: EdgeInsets.symmetric(
                    horizontal: (MediaQuery.of(context).size.width / 8)),
                child: Markdown(
                  data: getting_started_instalation_md,
                  selectable: true,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
