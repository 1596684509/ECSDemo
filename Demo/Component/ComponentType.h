#pragma once

// 用来记录组件数量
// 同时也是其位掩码所在位置
// 每增加一个组件就在Count前面加上
// Count用于设置组件用位掩码长度
enum class ComponentType {
	Position = 0,
	Velocity,
	InputKey,
	MoveState,
	Gravity,
	Jump,
	Camera,
	Count

};