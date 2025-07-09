# elo inflation

ELO inflation and deflation refer to long-term imbalances in a rating system where the average player rating either steadily increases (inflation) or decreases (deflation) over time, often distorting the meaning of rating itself. Inflation typically occurs when new players enter the system with low starting ratings and consistently lose to more experienced players, who then gain points disproportionately, pushing their ratings higher even if their skill hasn’t improved. Deflation, on the other hand, can happen when competent players are underrated at the start, causing others to lose more points than they should when facing them, resulting in an overall drop in ratings. To prevent these issues and preserve the integrity of the rating system, governing bodies like FIDE implement controls such as adjusting the K-factor (which determines how much ratings change after each game), introducing rating floors (minimum ELO a player can drop to), capping rating swings per game, and using a provisional phase for new players to stabilize their rating without heavily impacting the pool. These mechanisms help ensure that the ELO system remains stable, fair, and continues to reflect true relative skill over time.

# elo in general

ChatGPT said:
The ELO system is a mathematical rating system designed to estimate a player's skill based on performance against others. Each player starts with a rating (e.g., 1200), and every match adjusts ratings based on who wins and how strong the opponent is. The key idea is expected score—if a high-rated player beats a low-rated one, they gain only a few points, but if the low-rated player wins, they gain a lot. This is calculated using the formula:
Expected Score = 1 / (1 + 10^((OpponentRating - PlayerRating)/400)).
After a match, the actual result (1 for win, 0.5 for draw, 0 for loss) is compared with the expected score, and the difference determines how many points the player gains or loses. The magnitude of change is controlled by a constant called the K-factor, which can vary to make the system more or less responsive.

In-game, like in Arcadia: Rivals, this system is adapted to dynamically balance matchmaking and progression. When two players are matched, their trophies (which represent ELO) are used to calculate expected outcomes. After the match, their trophy counts are updated using the ELO formula. The system ensures players of similar skill fight, and winning against stronger players feels more rewarding. We also added layers like matchmaking history filters to avoid repetitive opponents, and ensured dungeon/bot matches use modified logic to avoid polluting real ELO dynamics. This lets the game maintain fair competition, smooth skill-based progression, and stable leaderboard rankings even as new players join or others become inactive.

Why 400?
It was chosen by Arpad Elo (the system's creator) based on empirical observations from chess.

A 400-point difference means the higher-rated player is expected to win about 91% of the time.

A 200-point difference gives the higher-rated player about a 75% win probability.

This value isn’t fixed across all games—it can be tuned depending on how steep or flat you want the win probability curve to be in your system. But 400 is the most commonly used default.

# map

In Arcadia: Rivals, the entire overworld is procedurally generated using a combination of seeded randomness, **Voronoi** diagrams, and Perlin noise. The process begins with a fixed seed, which ensures that the world layout remains consistent across sessions while still appearing random. A Voronoi diagram partitions the map into distinct polygonal regions, each representing a biome like steel, ground, psychic, or flying. Each biome polygon is populated with tiles using its respective biome class. Perlin noise is used to add smooth variation in terrain features, especially near dungeon areas, by simulating natural gradients and elevations. Dungeons are placed with slight offsets from polygon centers, and lootboxes are placed at sufficiently spaced coordinates within the polygon to avoid clustering. The system supports dynamic chunk loading based on player movement—only nearby chunks are active at a time for performance. This approach enables a vast, seamless, and unique world map to be generated and explored, all deterministically controlled by the initial seed.

# chunking

In Arcadia: Rivals, the game world is very large, so we use a technique called chunking to break it down into small, manageable square sections called chunks. Each chunk is like a mini-map of fixed size (for example, 16x16 tiles), and the world is made up of many such chunks placed next to each other. When the player moves, we calculate which chunk they are currently in and then load only the chunks around them (like a 5x5 area). Chunks that are far away from the player are unloaded to save memory and improve performance. Each chunk checks which region or "biome" it belongs to using the polygon data from procedural generation, and we load the correct terrain accordingly. If the chunk has a special location like a dungeon, that’s also handled during loading. This way, we create a seamless open world while keeping things efficient behind the scenes.

# google oauth workflow

OAuth is an open standard authorization protocol that allows third-party applications to access user data from a service like Google or GitHub without needing the user's password. Instead of sharing credentials, the user grants permission through a secure consent screen, and the service returns a temporary access token to the third-party app. This token is then used to fetch limited user data. In our project Arcadia, we used Google OAuth2 to allow players to sign in securely—when a user logs in with Google, we receive an access token from Google which we verify and use to retrieve basic user info like email, all without handling or storing their actual password, making authentication both secure and user-friendly.

# flow  (authorizatioon code flow.)

The Authorization Code Flow is the most secure OAuth2 flow, used by apps with a backend server. It works in multiple steps: First, the user is redirected to the OAuth provider (like Google) to log in and grant permission. Once approved, the provider redirects the user back to the app with a temporary authorization code. This code is then sent (from the backend server) to the OAuth provider’s token endpoint, along with the app's client credentials. If valid, the provider responds with an access token (and optionally a refresh token). The backend can now use this access token to securely access user data. This flow keeps tokens and client secrets hidden from the browser, making it ideal for secure server-based apps like Arcadia.

# refresh tokens

Refresh tokens are long-lived credentials used to obtain new access tokens after the current one expires. They are issued alongside the access token during OAuth authorization (usually in the Authorization Code Flow) and are stored securely by the client. Unlike access tokens, refresh tokens are not sent with every API request—they're only used to request new access tokens without requiring the user to log in again.

# redis leaderboard

Redis makes implementing a real-time leaderboard efficient using the Sorted Set (ZSET) data structure. Each player’s ID is stored as a member and their score as the score. Redis automatically keeps the set sorted by score, so to get top players, you just use ZRANGE or ZREVRANGE with scores. To update a score, ZINCRBY is used, and ZRANK or ZREVRANK gives the current rank of any player. Since all these operations are O(log n), the leaderboard remains fast and scalable even with thousands of players, making it ideal for games like Arcadia: Rivals that need frequent updates and real-time rankings.

# Q. Why did you choose Go (Golang) for the backend?
We chose Go for its concurrency model, which is ideal for a real-time game backend like Arcadia: Rivals. Goroutines and channels make it lightweight and efficient to handle thousands of WebSocket connections simultaneously. Go also has low latency, fast execution, and strong standard libraries for networking, which helped us build scalable and responsive systems like matchmaking, live game state, and leaderboard updates. Additionally, Go's simplicity and ease of deployment made development and debugging faster, especially in a collaborative team setting.


# why mysql ? why not mongo

We chose MySQL because our game needed strong relational consistency, especially for storing user data, match histories, and inventory transactions. These involve multiple related tables and ACID-compliant operations, which are better handled by a structured SQL database. MySQL provides strict schema enforcement, which helps catch errors early and keeps data integrity intact. On the other hand, MongoDB is schema-less and better for highly unstructured or evolving data, but our use case involved well-defined, structured data with complex joins—making MySQL a more reliable and efficient choice.