/*
 *  TApp.h
 *
 *  Created on: 09-07-2023
 *  Author: azeddine El Bassbasi
 */

#ifndef TESTS_MAIN_TAPP_H_
#define TESTS_MAIN_TAPP_H_
#include <mwtp/mwtp.h>
/*
 *
 */
class TApp : public MApp{
public:
	TApp(int args, char *argv[]);
	~TApp();
	void OnInit();
private:
	MFrame frame;
	MBox box;
};

#endif /* TESTS_MAIN_TAPP_H_ */
