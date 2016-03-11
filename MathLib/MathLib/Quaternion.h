#pragma once

struct Quaternion
{
public:
	Quaternion() :x(0), y(0), z(0), w(0){}

	union 
	{
		struct 
		{
			float x, y, z, w;
		};
		float v[4];
	};
};

