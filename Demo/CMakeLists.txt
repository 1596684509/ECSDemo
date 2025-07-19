# CMakeList.txt : Demo の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#

# ソースをこのプロジェクトの実行可能ファイルに追加します。

include_directories ("${CMAKE_SOURCE_DIR}/lib/include")
link_directories ("${CMAKE_SOURCE_DIR}/lib/lib")

add_executable (Demo "Demo.cpp" "Demo.h" "Utils/UUIDHandler.h" "Lib/glad.c" "Common/Const.h"     "Common/Entity.h" "Common/Entity.cpp" "Utils/UUIDHandler.cpp" "Component/Component.h"    "Component/Component.cpp"   "Common/World.h" "Utils/BitMask.h" "Utils/BitMask.cpp" "Component/ComponentType.h" "Component/Position.h" "Component/Position.cpp" "Common/ArcheType.cpp" "Common/ArcheType.h" "Common/World.cpp" "Component/Velocity.h" "Component/Velocity.cpp" "Component/ComponentBitMaskDigits.h"
        System/System.cpp
        System/System.h
        System/UpdateSystem.cpp
        System/UpdateSystem.h
        Component/InputKey.cpp
        Component/InputKey.h
        Component/MoveState.cpp
        Component/MoveState.h
        System/MoveUpdateSystem.cpp
        System/MoveUpdateSystem.h
        System/MoveInputSystem.cpp
        System/MoveInputSystem.h
        System/InputSystem.cpp
        System/InputSystem.h
        System/DrawSystem.cpp
        System/DrawSystem.h
        System/CharacterDrawSystem.h
        System/CharacterDrawSystem.cpp
)

target_link_libraries(Demo glfw3 opengl32)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Demo PROPERTY CXX_STANDARD 20)
endif()

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。