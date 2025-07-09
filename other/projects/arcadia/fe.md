# 4. How does collision detection work in Phaser?

Answer:
Phaser provides an Arcade Physics engine for lightweight collision handling. We added the player and interactive objects (like lootboxes and dungeon entrances) into physics groups and defined collisions using this.physics.add.collider. This way, we can trigger game logic when the player overlaps or collides with certain objects.

