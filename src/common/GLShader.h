#pragma once

#include <cstdint>

class GLShader
{
private:
	// un programme fait le liens entre Vertex Shader et Fragment Shader
	uint32_t m_Program;
	// Un Vertex Shader est execute pour chaque sommet (vertex)
    uint32_t m_VertexShader;
	// Un Geometry Shader est execute pour chaque primitive
	uint32_t m_GeometryShader;
	// Un Fragment Shader est execute pour chaque "pixel"
	// lors de la rasterization/remplissage de la primitive
	uint32_t m_FragmentShader;

	bool CompileShader(uint32_t type);

public:
	GLShader() {
        m_Program = 0;
        m_VertexShader = 0;
        m_GeometryShader = 0;
        m_FragmentShader = 0;
    }

	~GLShader() = default;

	inline uint32_t getProgram() const { return m_Program; }

	bool loadVertexShader(const char* filename);
	bool LoadGeometryShader(const char* filename);
	bool loadFragmentShader(const char* filename);
	bool create();
	void destroy();
};