#pragma once

// 用来记录组件数量
// 每增加一个组件就在Count前面加上
enum class ComponentType {
	Position = 0,
	Velocity,
	InputKey,
	MoveState,
	Gravity,
	Jump,
	Count

};