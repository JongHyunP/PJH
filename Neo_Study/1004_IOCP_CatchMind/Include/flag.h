#pragma once

enum SCENE_CREATE
{
	SC_CURRENT,
	SC_NEXT
};

enum SCENE_CHANGE
{
	SC_NONE,
	SC_CHANGE
};

enum COLLIDER_TYPE
{
	CT_RECT,
	CT_SPHERE,
	CT_LINE,
	CT_POINT,
	CT_PIXEL,
	CT_END
};

enum COLLISION_STATE
{
	CS_ENTER,
	CS_STAY,
	CS_LEAVE,
	CS_END
};