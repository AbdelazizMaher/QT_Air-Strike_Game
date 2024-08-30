# QT Air-Strike Game

**`QT Air-Strike Game`** is an arcade-style shooting game developed using `C++` and `Qt`. The game features a player-controlled ship that must shoot down incoming `enemies` while avoiding them to escape. The game tracks the `player's score` and `health`, and ends when the player's `health is depleted.`

## Modules Overview

### Game Module

---

- **`Functionality:`** Manages the overall game, including setting up the scene, handling key events, spawning enemies, and managing interactions between game entities like bullets and enemies.
- **`Logic:`** 
  - **Scene Management:** The `Game` class creates and manages a `QGraphicsScene` where all game entities (player, enemies, bullets, score, and health) are placed.
  - **Key Event Handling:** The `keyPressEvent` method captures left, right, and space key presses to move the player and fire bullets.
  - **Enemy Spawning:** A timer periodically spawns enemies using the `spawnEnemy` method.
  - **Bullet-Enemy Interaction:** The game listens for bullet collisions with enemies and updates the score or health accordingly.
- **`APIs Used:`** 
  - `QGraphicsView`, `QGraphicsScene` for managing the game view and entities.
  - `QKeyEvent` for handling player input.
  - `QMediaPlayer`, `QAudioOutput` for playing background music and sound effects.
- **`Signal-Slot Connections:`**
  - **Player:** Connects the player's `bulletFired` signal to the `onBulletFired` slot to handle bullet creation.
  - **Enemy:** Connects the enemy's `enemyDestroyed` signal to the `onEnemyDestroyed` slot to manage enemy removal and score updates.
  - **Health:** Connects the health's `healthDepleted` signal to the `onHealthDepleted` slot to handle game over logic.

### Player Module

---

- **`Functionality:`** Represents the player's ship, which can move left or right and fire bullets.
- **`Logic:`** 
  - **Movement:** The player can move left or right within the game boundaries using the `moveLeft` and `moveRight` methods.
  - **Shooting:** The player fires bullets when the space key is pressed, emitting the `bulletFired` signal.
- **`APIs Used:`** 
  - `QGraphicsPixmapItem` for representing the player's ship with an image.
  - `QKeyEvent` for detecting movement and firing actions.
- **`Signal-Slot Connections:`**
  - **Bullet Creation:** Emits the `bulletFired` signal when the player fires a bullet, triggering the bullet creation in the `Game` class.

### Bullet Module

---

- **`Functionality:`** Represents bullets fired by the player, which move upwards and interact with enemies.
- **`Logic:`** 
  - **Movement:** The bullet moves upwards on each timer tick using the `onFireTimeout` slot.
  - **Collision Detection:** The bullet checks for collisions with enemies and emits the `bulletCollided` signal if a collision is detected.
  - **Deletion:** The bullet emits the `bulletDestroyed` signal if it moves out of the screen.
- **`APIs Used:`** 
  - `QGraphicsPixmapItem` for representing the bullet with an image.
  - `QTimer` for controlling the bullet's movement.
- **`Signal-Slot Connections:`**
  - **Collision Handling:** Emits `bulletCollided` upon collision with an enemy, which is handled in the `Game` class.
  - **Bullet Removal:** Emits `bulletDestroyed` when the bullet moves off-screen, triggering its removal in the `Game` class.

### Enemy Module

---

- **`Functionality:`** Represents enemies that spawn at random positions at the top of the screen and move downwards.
- **`Logic:`** 
  - **Spawning:** Enemies spawn at random x-positions and move downwards using the `moveDown` slot.
  - **Interaction with Player/Bullets:** If an enemy collides with a bullet or moves out of the screen, it emits the `enemyDestroyed` signal with the appropriate `DeathCause`.
- **`APIs Used:`** 
  - `QGraphicsPixmapItem` for representing enemies with an image.
  - `QTimer` for controlling enemy movement.
  - `std::random_device`, `std::mt19937` for generating random spawn positions.
- **`Signal-Slot Connections:`**
  - **Destruction Handling:** Emits `enemyDestroyed` when an enemy is destroyed (either by a bullet or by moving off-screen), which updates the score or health in the `Game` class.

### Score Module

---

- **`Functionality:`** Tracks and displays the player's score.
- **`Logic:** 
  - **Score Management:** The score increases when an enemy is destroyed by a bullet.
  - **Display:** The current score is displayed on the screen and updated dynamically.
- **`APIs Used:`** 
  - `QGraphicsTextItem` for displaying the score on the screen.
- **`Signal-Slot Connections:`**
  - **Score Update:** The score is updated whenever the `increase` method is called, typically when an enemy is destroyed.

### Health Module

---

- **`Functionality:`** Tracks and displays the player's remaining health.
- **`Logic:** 
  - **Health Management:** The health decreases when an enemy moves off-screen without being destroyed.
  - **Game Over Handling:** When health reaches zero, the `healthDepleted` signal is emitted, triggering the game-over sequence.
- **`APIs Used:`** 
  - `QGraphicsTextItem` for displaying the health on the screen.
- **`Signal-Slot Connections:`**
  - **Health Depletion:** Emits `healthDepleted` when health reaches zero, which triggers the game-over sequence in the `Game` class.

## Qt APIs Used

---

- **`QGraphicsScene:`** Manages the scene that holds all the game entities (player, bullets, enemies, score, health).
- **`QGraphicsView:`** Provides the view for the `QGraphicsScene`, allowing the game to be displayed on the screen.
- **`QGraphicsItem/QGraphicsPixmapItem:`** Represents game entities like the player, bullets, and enemies with images.
- **`QGraphicsTextItem:`** Used for displaying textual information such as score and health on the screen.
- **`QTimer:`** Controls the timing of events, such as enemy movement and bullet firing.
- **`QKeyEvent:`** Captures and handles keyboard input for controlling the player.
- **`QMediaPlayer/QAudioOutput:`** Handles the background music and sound effects during the game.
- **`Signals and Slots:*`* Manages communication between different game entities, such as bullet collisions and enemy destruction.
- **`Parent-Child Relationship:`** Ensures proper memory management and event propagation between Qt objects, with `Game` as the parent of most game entities.

## Project Demo Video

[[Air Strike Demo]](https://youtu.be/zsGSoO69Vu0)
