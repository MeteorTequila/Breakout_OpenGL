#pragma once
#include <vector>
#include <tuple>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameLevel.h"
#include "PowerUp.h"

// 表示当前的游戏状态
enum GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
// 表示4个碰撞的可能方向
enum Direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Defines a Collision typedef that represents collision data
// 简单用tuple存储碰撞事件的信息，包括是否发生碰撞，碰撞的方向，
typedef std::tuple<GLboolean, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>

// 初始化玩家操控的滑板的大小
const glm::vec2 PLAYER_SIZE(100, 20);
// 初始化玩家操控的滑板的速度
const GLfloat PLAYER_VELOCITY(500.0f);
// 初始化球的速度
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// 球的半径
const GLfloat BALL_RADIUS = 12.5f;

// Game holds all game-related state and functionality.
// Combines all game-related data into a single class for
// easy access to each of the components and manageability.
class Game
{
public:
    // Game state
    GameState State;
    GLboolean Keys[1024];
    GLuint Width, Height;
    std::vector<GameLevel> Levels;
    std::vector<PowerUp> PowerUps;
    GLuint Level;
    // Constructor/Destructor
    Game(GLuint width, GLuint height);
    ~Game();
    // Initialize game state (load all shaders/textures/levels)
    void Init();
    // GameLoop
    void ProcessInput(GLfloat dt);
    void Update(GLfloat dt);
    void Render();
    void DoCollisions();
    void SpawnPowerUps(GameObject &block);
    void UpdatePowerUps(GLfloat dt);
    // Reset
    void ResetLevel();
    void ResetPlayer();
};