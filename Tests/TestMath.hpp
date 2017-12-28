#ifndef NU_TESTMATH_HPP
#define NU_TESTMATH_HPP

#include "../Sources/Math/Utilities.hpp"
#include "../Sources/Math/Trigonometry.hpp"
#include "../Sources/Math/Vector2.hpp"
#include "../Sources/Math/Vector3.hpp"
#include "../Sources/Math/Vector4.hpp"
#include "../Sources/Math/Matrix3.hpp"
#include "../Sources/Math/Matrix4.hpp"
#include "../Sources/Math/Quaternion.hpp"
#include "../Sources/Math/Random.hpp"
#include "../Sources/Math/Noise.hpp"
#include "../Sources/Math/AABB.hpp"
#include "../Sources/Math/Plane.hpp"
#include "../Sources/Math/Ray.hpp"
#include "../Sources/Math/Rect.hpp"
#include "../Sources/Math/Sphere.hpp"
#include "../Sources/Math/OBB.hpp"
#include "../Sources/Math/Intersection.hpp"
#include "../Sources/Math/Frustum.hpp"

#include "../Sources/System/UnitTest.hpp"

BEGIN_TEST(Math)
{

TEST("Utilities")
{
	CHECK(nu::floor(2.0f) == 2);
	CHECK(nu::ceil(2.0f) == 2);
	CHECK(nu::floor(2.4f) == 2);
	CHECK(nu::ceil(2.4f) == 3);
	CHECK(nu::floor(-2.7f) == -3);
	CHECK(nu::ceil(-2.7f) == -2);
	CHECK(nu::floor(-2.0f) == -2);
	CHECK(nu::ceil(-2.0f) == -2);
	CHECK(nu::clamp(50, 0, 10) == 10);
	CHECK(nu::clamp(50, 0, 100) == 50);
	CHECK(nu::clamp(50, 100, 1000) == 100);
	CHECK(nu::inRange(50, 0, 100));
	CHECK(nu::equals(50.0000f, 50.0001f, 0.01f));
}

TEST("Trigonometry")
{
	CHECK(nu::equals(nu::cos(90.0f), 0.0f));
	CHECK(nu::equals(nu::cos(0.0f), 1.0f));
	CHECK(nu::equals(nu::sin(90.0f), 1.0f));
	CHECK(nu::equals(nu::sin(0.0f), 0.0f));
}

TEST("Vector2")
{
	nu::Vector2f vec;
}

TEST("Vector3")
{
	nu::Vector3f vec;
}

TEST("Vector4")
{
	nu::Vector4f vec;
}

TEST("Matrix3")
{
	nu::Matrix3f mat;

	// Inverse
	nu::Matrix3f invTest(2, 0, -1, 0, 1, 0, 1, 0, 1);
	nu::Matrix3f invResult(1 / 3.f, 0, 1 / 3.f, 0, 1, 0, -1 / 3.f, 0, 2 / 3.f);
	CHECK(invTest.inversed() == invResult);
	CHECK(invTest.inverse() == invResult);
	CHECK(invResult.inversed().inversed() == invResult);

	// Transpose
	nu::Matrix3f transposeTest(0, 1, 2, 3, 4, 5, 6, 7, 8);
	nu::Matrix3f transposeResult(0, 3, 6, 1, 4, 7, 2, 5, 8);
	CHECK(transposeTest.transposed() == transposeResult);
	CHECK(transposeTest.transpose() == transposeResult);
	CHECK(transposeResult.transposed().transposed() == transposeResult);
}

TEST("Matrix4")
{
	nu::Matrix4f mat;

	// Inverse
	nu::Matrix4f invTest(2, 0, -1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1);
	nu::Matrix4f invResult(1 / 3.f, 0, 1 / 3.f, 0, 0, 1, 0, 0, -1 / 3.f, 0, 2 / 3.f, 0, 0, 0, 0, 1);
	CHECK(invTest.inversed() == invResult);
	CHECK(invTest.inverse() == invResult);
	CHECK(invResult.inversed().inversed() == invResult);

	// Transpose
	nu::Matrix4f transposeTest(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	nu::Matrix4f transposeResult(0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15);
	CHECK(transposeTest.transposed() == transposeResult);
	CHECK(transposeTest.transpose() == transposeResult);
	CHECK(transposeResult.transposed().transposed() == transposeResult);
}

TEST("Quaternion")
{
	nu::Quaternionf quat;
}

TEST("Random")
{
	I32 min = 0;
	I32 max = 100000000;
	I32 times = 10;

	nu::RandomEngine random1(12345);
	nu::RandomEngine random2(345678376);
	nu::RandomEngine random3(12345);

	for (I32 i = 0; i < times; i++)
	{
		I32 n1 = random1.get(min, max);
		I32 n2 = random2.get(min, max);
		I32 n3 = random3.get(min, max);
		I32 n4 = nu::Random::get(min, max);

		CHECK(n1 == n3);
		CHECK(n1 != n2);
		CHECK(n1 != n4);
	}
}

TEST("Noise")
{
	nu::Noise noise;
	for (U32 x = 0; x < 100; x++)
	{
		for (U32 y = 0; y < 100; y++)
		{
			noise.getNoise(x * 0.01f, y * 0.01f);
		}
	}
}

TEST("AABB")
{
	nu::AABB box;

}

TEST("Plane")
{
	nu::Plane plane;

}

TEST("Ray")
{
	nu::Ray ray;

}

TEST("Rect")
{
	nu::Rectf rect;

}

TEST("Sphere")
{
	nu::Sphere sphere;

}

TEST("OBB")
{
	nu::OBB box;

}

TEST("Intersection")
{
	

}

TEST("Frustum")
{
	nu::Frustum frustum;

}

}
END_TEST;

#endif // NU_TESTMATH_HPP
