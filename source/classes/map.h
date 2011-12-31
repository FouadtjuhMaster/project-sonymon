class MAP
{
      public:
            MAP();
            ~MAP();
             
            inline unsigned short GetTile(OSL_MAP *m, int col, int row);
            inline int CheckTileCollision(OSL_MAP *m, OSL_IMAGE * image, int direction);
             
      private:
              
}map;

inline unsigned short MAP::GetTile(OSL_MAP *m, int col, int row)
{
  u16 *map = (u16*)m->map;
  return map[row*m->mapSizeX + col];
}

int MAP::CheckTileCollision(OSL_MAP *m, OSL_IMAGE * image, int direction)
{
  int tile = 0;
  
  if(direction == 0){
    tile = GetTile(m,((m->scrollX + image->x - 0))/ m->tileX, (m->scrollY + image->y + image->stretchY)/ m->tileY);
    //if(!tile) tile = GetTile(m,((m->scrollX + image->x - 0))/ m->tileX, (m->scrollY + image->y)/ m->tileY);
  }

  else if(direction == 1){
    tile = GetTile(m,((m->scrollX + image->x +image->stretchX + 0))/ m->tileX, (m->scrollY + image->y + image->stretchY)/ m->tileY);
    //if (!tile) tile = GetTile(m,((m->scrollX + image->x +image->stretchX + 0))/ m->tileX, (m->scrollY + image->y)/ m->tileY);
  }

  else if(direction == 2){
    tile = GetTile(m,((m->scrollX + image->x +image->stretchX ))/ m->tileX, (m->scrollY + image->y - 0)/ m->tileY);
    //if (!tile) tile = GetTile(m,((m->scrollX + image->x))/ m->tileX, (m->scrollY + image->y - 0)/ m->tileY);
  }

  else if(direction == 3){
    tile = GetTile(m,((m->scrollX + image->x +image->stretchX ))/ m->tileX, (m->scrollY + image->y + image->stretchY + 0)/ m->tileY);
    //if (!tile) tile = GetTile(m,((m->scrollX + image->x))/ m->tileX, (m->scrollY + image->y + image->stretchY + 0)/ m->tileY);
  }
  
  else oslFatalError("INVALID PARAMETER PASSED TO CheckTileCollision()!!!");
  

  if(tile == STONE_WALL_OVERHEAD_TOP)
	return 0;

  else if(tile == STONE_WALL_OVERHEAD)
	return 0;
	
  else if(tile == STONE_WALL)
	return 0;
	
  
  return 1;
  
}

MAP::MAP()
{    
     return;
}
MAP::~MAP()
{
     return;
}



