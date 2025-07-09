✅ Core Concepts
What is Redis and what are its key features?
→ In-memory, key-value store; supports persistence, data structures, pub/sub, fast reads/writes.

How does Redis achieve high performance?
→ In-memory storage, single-threaded event loop, non-blocking I/O.

What data structures does Redis support?
→ Strings, Hashes, Lists, Sets, Sorted Sets (ZSET), Bitmaps, HyperLogLogs, Streams, Geo.

Difference between Redis and Memcached?
→ Redis has richer data types, persistence, replication, Lua scripting.

✅ Persistence & Durability
What are RDB and AOF? How do they differ?

RDB: Snapshotting at intervals; smaller files, faster load.

AOF: Append-only log of every write; more durable, slower to load.

Can be used together.

How does Redis recover from failure?
→ Uses RDB/AOF to reconstruct data; supports replication and persistence.

What happens if Redis runs out of memory?
→ Depends on eviction policy (noeviction, allkeys-lru, etc.); can crash or evict data.

✅ Leaderboards & Sorted Sets
How do you implement a leaderboard in Redis?
→ Using ZADD, ZRANGE, ZRANK, ZREVRANGE, ZINCRBY with a sorted set.
→ Fast insertion, rank lookup, and range queries.

How do you get a player’s rank and score?
→ ZREVRANK for rank, ZSCORE for score.

How do you display top-N players efficiently?
→ ZREVRANGE key 0 N-1 WITHSCORES

How do you update a player’s score?
→ ZINCRBY leaderboard score_increment player_id

✅ Concurrency & Scaling
How does Redis handle concurrent writes?
→ Single-threaded model ensures atomic command execution.

How to handle race conditions?
→ Use Lua scripts or transactions (MULTI, EXEC).

How does Redis Cluster work?
→ Sharding across multiple nodes; each key belongs to a slot (0–16383).

Can Redis scale horizontally?
→ Yes, using Redis Cluster or client-side sharding.

✅ Use Cases & Reliability
How would you use Redis for caching?
→ Store frequently accessed data; use TTL via SETEX, EXPIRE.

What is a cache stampede and how do you prevent it?
→ Multiple requests trying to populate missing cache → use lock or randomized TTL.

What are Redis Pub/Sub and Streams used for?
→ Pub/Sub: real-time messaging; Streams: persistent event log, consumer groups.

How do you implement session storage using Redis?
→ Store user sessions as key-value pairs, set expiry with TTL.

How to persist in-memory game state with Redis?
→ Serialize and store state periodically, or on game events; can use HASH or STRING.

