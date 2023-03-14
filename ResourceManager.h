#pragma once

#include <map>
#include <string>

#include <GL/glew.h>

#include "Texture.h"
#include "Shader.h"

class ResourceManager
{
public:
    // 存储资源（shader和textures）
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;
    // Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
    // 从shader中载入
    static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
    // Retrieves a stored shader
    // 获取存储的shader
    static Shader &GetShader(std::string name);
    // Loads (and generates) a texture from file
    // 从文件中加载并且产生纹理
    static Texture2D LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
    // Retrieves a stored texture
    // 获取存储的纹理
    static Texture2D &GetTexture(std::string name);
    // Properly de-allocates all loaded resources
    // 释放所有加载的资源
    static void Clear();

private:
    // Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() {}
    // Loads and generates a shader from file
    // 从文件中加载shader
    static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
    // Loads a single texture from file
    // 从文件中加载texture
    static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};
