// Demo.h : 標準のシステム インクルード ファイル用のインクルード ファイル、
// または、プロジェクト専用のインクルード ファイル。

#pragma once

#include <windows.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include "Common/Const.h"
#include "Utils/BitMask.h"
#include "Common/Entity.h"
#include "Component/Position.h"
#include "Common/ArcheType.h"
#include "Common/World.h"
#include "Component/Velocity.h"
#include "System/MoveInputSystem.h"
#include "System/CharacterDrawSystem.h"
#include "System/MoveUpdateSystem.h"


// TODO: プログラムに必要な追加ヘッダーをここで参照します。
