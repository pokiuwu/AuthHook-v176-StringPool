# v176 AuthHook + StringPool
Enhanced AuthHook for v176 that includes StringPool



#Usage of StringPool
You'll need an unpacked dump of v176 MapleStory.exe which can be found here:
https://drive.google.com/file/d/1Xy-GBCMF5FhFF4QTsWxKypKbQdXXKu9-/view?usp=sharing


You'll also need STREDIT which can be found here (this STREDIT is also updated and will work for higher versions as well, tested up to v223):
https://drive.google.com/file/d/1fiUi7Yapv9hV0WzWr5F5GEyJCVEL-w4c/view?usp=sharing

After downloading both the unpacked dump of v176 and STREDIT, open up STREDIT as admin and load the v176 dump file
It will take a few moments and you should see a list of strings, using the StringPool you can edit any of those string to your liking, for example:

ID 4479 "Ver. %d.%d" is the version of the game that is shows at the top right of the login screen, you can edit to say whatever you'd like, example:


(https://images-ext-1.discordapp.net/external/jEX7VeHgguFqLPCNO8Zbx3oldRUWWY9xjLzOdi2dvNw/https/i.imgur.com/xaeJIin.png?width=734&height=574)



#How to build
Go to Global.h and change the localhost address (OPT_ADDR_HOSTNAME) to yours if you want to make the server public, otherwise keep it at 127.0.0.1
Build in x86 not x64!
Create a bat file with the following command: `MapleStory.exe GameLaunching 8.31.99.141 8484` [make sure it's in your v176 folder]



#Credits
Rajan for the original AuthHook code
