//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef MESHLOADER_OBJ
#define MESHLOADER_OBJ

#include <string>

class rcMeshLoaderObj
{
public:
	rcMeshLoaderObj();
	~rcMeshLoaderObj();
	
	bool load(const std::string& fileName);

	const float* getVerts() const { return m_verts; }
	const float* getNormals() const { return m_normals; }
	const int* getTris() const { return m_tris; }
	int getVertCount() const { return m_vertCount; }
	int getTriCount() const { return m_triCount; }
	const std::string& getFileName() const { return m_filename; }

private:
	// Explicitly disabled copy constructor and copy assignment operator.
	rcMeshLoaderObj(const rcMeshLoaderObj&);
	rcMeshLoaderObj& operator=(const rcMeshLoaderObj&);
	
	void addVertex(float x, float y, float z, int& cap);
	void addTriangle(int a, int b, int c, int& cap);
	
	std::string m_filename;
	float m_scale;	
	float* m_verts;   // 所有顶点的坐标，平铺存放，m_verts[0,1,2]是第一个点、m_verts[3,4,5]是第二个点
	int* m_tris;    // 所有三角面的顶点索引，m_tris[0,1,2]是第一个三角面的三个顶点索引，m_tris[3,4,5]是第二个三角面的三个顶点索引
	float* m_normals;  // 法线向量，m_normals[0,1,2]是第一个三角面的法线，m_normals[3,4,5]是第二个三角面的法线
	int m_vertCount;
	int m_triCount;
};

#endif // MESHLOADER_OBJ
