
#include<utility>

using namespace std;

class Point2D
{
public:
	float x;
	float y;
};

class Rectangle
{
private:
	Point2D vertices[4];

public:
	void set(Point2D point1, Point2D point2, Point2D point3, Point2D point4)
	{
		vertices[0] = move(point1);
		vertices[1] = move(point2);
		vertices[2] = move(point3);
		vertices[3] = move(point4);
	}

	Rectangle(Point2D point1, Point2D point2, Point2D point3, Point2D point4)
	{
		set(move(point1), move(point2), move(point3), move(point4));
	}

	Rectangle(const Rectangle & obj)
	{
		set(obj.vertices[0], obj.vertices[1], obj.vertices[2], obj.vertices[3]);
	}

	Rectangle operator=(const Rectangle &obj)
	{
		set(obj.vertices[0], obj.vertices[1], obj.vertices[2], obj.vertices[3]);
		return *this;
	}
	
	const Point2D* get_vertices() const
	{
		return vertices;
	}

	~Rectangle()
	{

	}
};


bool collide(const Rectangle & lhs, const Rectangle & rhs)
{
	for (auto i = 0; i < sizeof(rhs.get_vertices) / sizeof(Point2D); ++i)
	{
		const auto vertex = rhs.get_vertices[i];
		if (collide(lhs, vertex))
		{
			return true;
		}
	}
	return false;
}

bool collide(const Rectangle & lhs, const Point2D & rhs)
{
	float min_x;
	float max_x;
	float min_y;
	float max_y;

	for (auto i = 0; i < sizeof(lhs.get_vertices)/sizeof(Point2D); ++i)
	{
		const auto vertex = lhs.get_vertices[i];

		if (i == 0)
		{
			min_x = vertex.x;
			max_x = vertex.x;
		  min_y = vertex.y;
			max_y = vertex.y;
			continue;
		}

		if (min_x > vertex.x)
		{
			min_x = vertex.x;
		}

		if (max_x < vertex.x)
		{
			max_x = vertex.x;
		}

		if (min_y > vertex.y)
		{
			min_y = vertex.y;
		}

		if (max_y > vertex.y)
		{
			max_y = vertex.y;
		}
	}

	return (rhs.x <= max_x &&  rhs.x >= min_x) &&
		(rhs.y <= max_y &&  rhs.y >= min_y);
}

int main()
{
	Point2D point_1 = { 3.0, 2.0 };
	Rectangle retangle(Point2D{ 0.0, 0.0 }, Point2D{ 0.0, 2.0 }, Point2D{ 2.0, 2.0 }, Point2D{ 2.0, 0.0 });
	return 0;
}