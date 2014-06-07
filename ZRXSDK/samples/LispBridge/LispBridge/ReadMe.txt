Description: 

This sample demonstrates the use of transference between arx and lisp:

 1) Call an extern lisp function in ZRX  applications.
 2) Call an extern ZRX  function in lisp applications.

In order to look this feature, you should do some events before.

Firstly, start your zwcad application. and type the "appload" command to load LispBridge.dll. 
During the process, the lisp application "drawline.lsp" will be load.

Operations:

1) Command "InvkLsp" demonstrates use zcedQueueExpr to call an extern lisp function in zrx application. 

2) Enter "(entgetxx)" or "(entlastxx))" in command line or in the .lsp file, it demonstrates how to call an extern zrx functions in lisp app.
for example, you can enter "(entgetxx (entlastxx))" to get the last maked entity infomation.

Note: If the macro _USING_INVKSUBRMSG is defined, it will demonstrates the usage of ZcRx::kInvkSubrMsg in your application for run a lisp defined function.

