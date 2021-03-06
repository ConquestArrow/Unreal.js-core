#pragma once

#include "Core.h"
#include "Engine.h"
#include "Networking.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "ModuleManager.h"

// Interfaces
#include "IJavascriptWebSocketModule.h"

class FJavascriptWebSocket;
class FJavascriptWebSocketServer;

#if PLATFORM_WINDOWS
#include "AllowWindowsPlatformTypes.h"
#endif

#ifndef THIRD_PARTY_INCLUDES_START
#	define THIRD_PARTY_INCLUDES_START
#	define THIRD_PARTY_INCLUDES_END
#endif

THIRD_PARTY_INCLUDES_START

#define UI UI_ST
#ifndef LWS_INCLUDED
#include "libwebsockets.h"
#define LWS_INCLUDED
#define LWS_EXTERN extern
//#include "private-libwebsockets.h"
#endif
#undef UI

THIRD_PARTY_INCLUDES_END

#if PLATFORM_WINDOWS
#include "HideWindowsPlatformTypes.h"
#endif

typedef struct lws_context WebSocketInternalContext;
typedef struct lws WebSocketInternal;
typedef struct lws_protocols WebSocketInternalProtocol;

DECLARE_DELEGATE_TwoParams(FJavascriptWebSocketPacketRecievedCallBack, void* /*Data*/, int32 /*Data Size*/);
DECLARE_DELEGATE_OneParam(FJavascriptWebSocketClientConnectedCallBack, FJavascriptWebSocket* /*Socket*/);
DECLARE_DELEGATE(FJavascriptWebSocketInfoCallBack);

DECLARE_LOG_CATEGORY_EXTERN(LogWebsocket, Warning, All);
