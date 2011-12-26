class MAP
{
      public:
            MAP();
            ~MAP();
             
             inline unsigned short GetTile(OSL_MAP *m, int col, int row);
             
      private:
              
}map;

inline unsigned short MAP::GetTile(OSL_MAP *m, int col, int row)
{
  u16 *map = (u16*)m->map;
  return map[row*m->mapSizeX + col];
}

#define TOP_DIRT FR1_map[0][0]

#define DIRT FR1_map[0][1]

#define STONE_WALL FR1_map[0][5]

#define STONE_WALL_OVERHEAD FR1_map[15][4]

#define STONE_WALL_OVERHEAD_TOP FR1_map[50][0]

#define GRAY_ROAD FR1_map[2][6]

#define GRAY_ROAD_TOP FR1_map[2][6]

MAP::MAP()
{    
     return;
}
MAP::~MAP()
{
     return;
}



