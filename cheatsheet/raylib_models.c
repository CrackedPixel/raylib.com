
    // Basic geometric 3D shapes drawing functions
    void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color);                                    // Draw a line in 3D world space
    void DrawPoint3D(Vector3 position, Color color);                                                   // Draw a point in 3D space, actually a small line
    void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color); // Draw a circle in 3D world space
    void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);                              // Draw a color-filled triangle (vertex in counter-clockwise order!)
    void DrawTriangleStrip3D(Vector3 *points, int pointsCount, Color color);                           // Draw a triangle strip defined by points
    void DrawCube(Vector3 position, float width, float height, float length, Color color);             // Draw cube
    void DrawCubeV(Vector3 position, Vector3 size, Color color);                                       // Draw cube (Vector version)
    void DrawCubeWires(Vector3 position, float width, float height, float length, Color color);        // Draw cube wires
    void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);                                  // Draw cube wires (Vector version)
    void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured
    void DrawSphere(Vector3 centerPos, float radius, Color color);                                     // Draw sphere
    void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);            // Draw sphere with extended parameters
    void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);         // Draw sphere wires
    void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone
    void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color); // Draw a cylinder/cone wires
    void DrawPlane(Vector3 centerPos, Vector2 size, Color color);                                      // Draw a plane XZ
    void DrawRay(Ray ray, Color color);                                                                // Draw a ray line
    void DrawGrid(int slices, float spacing);                                                          // Draw a grid (centered at (0, 0, 0))

    // Model loading/unloading functions
    Model LoadModel(const char *fileName);                                                             // Load model from files (meshes and materials)
    Model LoadModelFromMesh(Mesh mesh);                                                                // Load model from generated mesh (default material)
    void UnloadModel(Model model);                                                                     // Unload model (including meshes) from memory (RAM and/or VRAM)
    void UnloadModelKeepMeshes(Model model);                                                           // Unload model (but not meshes) from memory (RAM and/or VRAM)

    // Mesh loading/unloading functions
    void UploadMesh(Mesh *mesh, bool dynamic);                                                         // Upload vertex data into GPU and provided VAO/VBO ids
    void UpdateMeshBuffer(Mesh mesh, int index, void *data, int dataSize, int offset);                  // Update mesh vertex data in GPU for a specific buffer index
    void DrawMesh(Mesh mesh, Material material, Matrix transform);                                     // Draw a 3d mesh with material and transform
    void DrawMeshInstanced(Mesh mesh, Material material, Matrix *transforms, int instances);           // Draw multiple mesh instances with material and different transforms
    void UnloadMesh(Mesh mesh);                                                                        // Unload mesh data from CPU and GPU
    bool ExportMesh(Mesh mesh, const char *fileName);                                                  // Export mesh data to file, returns true on success

    // Material loading/unloading functions
    Material *LoadMaterials(const char *fileName, int *materialCount);                                 // Load materials from model file
    Material LoadMaterialDefault(void);                                                                // Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)
    void UnloadMaterial(Material material);                                                            // Unload material from GPU memory (VRAM)
    void SetMaterialTexture(Material *material, int mapType, Texture2D texture);                       // Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)
    void SetModelMeshMaterial(Model *model, int meshId, int materialId);                               // Set material for a mesh

    // Model animations loading/unloading functions
    ModelAnimation *LoadModelAnimations(const char *fileName, int *animsCount);                        // Load model animations from file
    void UpdateModelAnimation(Model model, ModelAnimation anim, int frame);                            // Update model animation pose
    void UnloadModelAnimation(ModelAnimation anim);                                                    // Unload animation data
    void UnloadModelAnimations(ModelAnimation* animations, unsigned int count);                        // Unload animation array data
    bool IsModelAnimationValid(Model model, ModelAnimation anim);                                      // Check model animation skeleton match

    // Mesh generation functions
    Mesh GenMeshPoly(int sides, float radius);                                                         // Generate polygonal mesh
    Mesh GenMeshPlane(float width, float length, int resX, int resZ);                                  // Generate plane mesh (with subdivisions)
    Mesh GenMeshCube(float width, float height, float length);                                         // Generate cuboid mesh
    Mesh GenMeshSphere(float radius, int rings, int slices);                                           // Generate sphere mesh (standard sphere)
    Mesh GenMeshHemiSphere(float radius, int rings, int slices);                                       // Generate half-sphere mesh (no bottom cap)
    Mesh GenMeshCylinder(float radius, float height, int slices);                                      // Generate cylinder mesh
    Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);                                // Generate torus mesh
    Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);                                 // Generate trefoil knot mesh
    Mesh GenMeshHeightmap(Image heightmap, Vector3 size);                                              // Generate heightmap mesh from image data
    Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);                                            // Generate cubes-based map mesh from image data

    // Mesh manipulation functions
    BoundingBox GetMeshBoundingBox(Mesh mesh);                                                            // Compute mesh bounding box limits
    void MeshTangents(Mesh *mesh);                                                                     // Compute mesh tangents
    void MeshBinormals(Mesh *mesh);                                                                    // Compute mesh binormals

    // Model drawing functions
    void DrawModel(Model model, Vector3 position, float scale, Color tint);                            // Draw a model (with texture if set)
    void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model with extended parameters
    void DrawModelWires(Model model, Vector3 position, float scale, Color tint);                       // Draw a model wires (with texture if set)
    void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint); // Draw a model wires (with texture if set) with extended parameters
    void DrawBoundingBox(BoundingBox box, Color color);                                                // Draw bounding box (wires)
    void DrawBillboard(Camera camera, Texture2D texture, Vector3 center, float size, Color tint);      // Draw a billboard texture
    void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 center, float size, Color tint); // Draw a billboard texture defined by source

    // Collision detection functions
    bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);        // Detect collision between two spheres
    bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                      // Detect collision between two bounding boxes
    bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);                       // Detect collision between box and sphere
    bool CheckCollisionRaySphere(Ray ray, Vector3 center, float radius);                               // Detect collision between ray and sphere
    bool CheckCollisionRaySphereEx(Ray ray, Vector3 center, float radius, Vector3 *collisionPoint);    // Detect collision between ray and sphere, returns collision point
    bool CheckCollisionRayBox(Ray ray, BoundingBox box);                                               // Detect collision between ray and box
    RayHitInfo GetCollisionRayMesh(Ray ray, Mesh mesh, Matrix transform);                              // Get collision info between ray and mesh
    RayHitInfo GetCollisionRayModel(Ray ray, Model model);                                             // Get collision info between ray and model
    RayHitInfo GetCollisionRayTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                   // Get collision info between ray and triangle
    RayHitInfo GetCollisionRayGround(Ray ray, float groundHeight);                                     // Get collision info between ray and ground plane (Y-normal plane)

