// Demo.h : 標準のシステム インクルード ファイル用のインクルード ファイル、
// または、プロジェクト専用のインクルード ファイル。

#pragma once

#include <windows.h>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Utils/BitMask.h"
#include "Common/Const.h"
#include "Common/Entity.h"
#include "Common/ArcheType.h"
#include "Common/World.h"

#include "Component/Position.h"
#include "Component/Velocity.h"
#include "Component/Gravity.h"

#include "System/CharacterDrawSystem.h"
#include "System/MoveUpdateSystem.h"
#include "System/GravityUpdateSystem.h"

#include "Listener/MoveInputListener.h"
#include "Listener/JumpListener.h"


// TODO: プログラムに必要な追加ヘッダーをここで参照します。
