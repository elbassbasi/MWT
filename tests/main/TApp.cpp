/*
 *  TApp.cpp
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#include "TApp.h"
int main(int args, char *argv[]) {
	TApp app(args, argv);
	app.OnInit();
	return app.run();
}

TApp::TApp(int args, char *argv[])
	:MApp(args,argv) {
	frame.setStyle(MSTYLE_FRAME_TRIM | MSTYLE_FRAME_DISPOSE_ON_CLOSE);
}

TApp::~TApp() {

}

void TApp::OnInit() {
	frame.create(MSTYLE_FRAME_TRIM | MSTYLE_FRAME_DISPOSE_ON_CLOSE);
	box.create(&frame,MSTYLE_HORIZONTAL);
	frame.setVisible(true);
}
