
Description: 
This program demonstrates using demand loading. In order to look this feature, you should do some events before.
Firstly, start your ZWCAD application. and type the "appload" command to load DemandLoading.dll.
Secondly, implement the "RegLoadInfo" command to register loading infomation in the system registry. 
At last, unload DemandLoading.dll by type same "appload" command on command line.

Demand Loading On Command Invocation:
1. Type the PrintInfo command on command line
2. ZWCAD will load the DemandLoading.dll according the registery infomation, then run this command.

Demand Loading On Detection Of Custom Objects:
1. Open a drawing with the "SignEntity" entity.  
2. ZWCAD will load the DemandLoading.dll automatically according the registery infomation