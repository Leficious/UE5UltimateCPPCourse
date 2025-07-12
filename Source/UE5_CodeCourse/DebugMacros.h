#pragma once
#include "DrawDebugHelpers.h"

//a macro can also call a function
#define DRAW_SPHERE(Location, Size) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, Size, 12, FColor::Red, true);
#define DRAW_SPHERE_SINGLEFRAME(Location, Size) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, Size, 12, FColor::Red, false, -1.f);
#define DRAW_LINE(StartLocation, EndLocation, Size) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, Size);
#define DRAW_LINE_SINGLEFRAME(StartLocation, EndLocation, Size) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, Size);
#define DRAW_POINT(Location, Size) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, Size, FColor::Red, true);
#define DRAW_POINT_SINGLEFRAME(Location, Size) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, Size, FColor::Red, false, -1.f);
#define DRAW_CONE(Location, Rotation, Size) if (GetWorld()) DrawDebugCone(GetWorld(), Location, Rotation, 75.f, 0.5f, 0.5f, 8, FColor::Red, true, -1.f, 0, Size);
#define DRAW_BOX(Location, Extent) if (GetWorld()) DrawDebugBox(GetWorld(), Location, Extent, FColor::Red, true, -1.f, 0, 1.f);

//for each new line in a macro you must add a slash per new line
#define DRAW_VECTOR(StartLocation, EndLocation, Rotation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 5.f, FColor::Red, true); \
		DrawDebugCone(GetWorld(), EndLocation, Rotation, 50.f, 0.5f, 0.5f, 8, FColor::Red, true, -1.f, 0, 1.f); \
	}
#define DRAW_VECTOR_SINGLEFRAME(StartLocation, EndLocation, Rotation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 5.f, FColor::Red, false, -1.f); \
		DrawDebugCone(GetWorld(), EndLocation, Rotation, 50.f, 0.5f, 0.5f, 8, FColor::Red, false, -1.f, 0, 1.f); \
	}