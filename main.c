//main.c
#include <b_org.h>
#include <b_gui.h>
#include <b_srv.h>
#include <b_imp.h>
#include <b_pdata.h>
#include <b_err.h>
#include <stdlib.h>
//universal variables
char SrvMsg;
int organizer,opengl,server,imput,player1,player2,error;//this way the objects can be called from the scripts

int main()
{
bool ReEntry;
organizer = b_org(); //at somepoint when we have more than 1 type of battle add functions to the constructor
opengl = b_gui();
error = b_err();
server = b_srv(address of server, start port number to use, highest port number to use);
player1 = b_pdata();
player2 = b_pdata();
player1.GetLocData(); //get local data from playerfile or something idk yet
server.CnfrmData(player1.C_Array);//make sure the data matches that of the server
char MsgHand[256];

	MsgHand = server.request();//ask if any other players are available for battle
if (MsgHand != "yes" && MsgHand != NULL) error.alert("server failure");
else
	{
		if(MsgHand == NULL) error.fatal("server returned null");
}
server.accept();
	opengl.MatchLoad();
server.GetPData(player2);
server.send("rdy");
SrvMsg = server.GetMsg();

while ( SrvMsg[1,3] != "end")
{
	SrvMsg = server.GetMsg();
	error.check(SrvMsg,organizer,opengl,server,player1,player2) //makes sure no values = null
	organizer.MsgLoop(SrvMsg);// checks if anything has happened in the last 30th of a second on the server
	organizer.imput(); //checks for imput
	organizer.battleloop();//does damage etc Gui called within
	organizer.update(); //updates server on whats happened
	//yea more or less everything in the loops will be called in the above functions
}
return 0;
}
