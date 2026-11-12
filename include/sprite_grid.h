/* The scrolling sprite grid widget built by CreateSpriteGrid: a rows x columns
 * raster of fixed sprite cells that shows a window of the grid's items and
 * scrolls through them a row at a time, its pixel offset animating.  The cell
 * block is a fixed array of SpriteCell records stored as a SpriteCellList. */
#ifndef SPRITE_GRID_H
#define SPRITE_GRID_H

/* One cell of a sprite-cell block: the screen rectangle it covers and the
 * graphic it shows.  12 bytes; AddSpriteCell fills the first free cell. */
typedef struct SpriteCell {
    s16 x;      /* +0x00 screen x of the cell */
    s16 y;      /* +0x02 screen y of the cell */
    s16 width;  /* +0x04 cell width in pixels */
    s16 height; /* +0x06 cell height in pixels */
    u16 tile;   /* +0x08 graphic/tile index */
    u16 attr;   /* +0x0A attribute passed by the caller; 0 = cell is free */
} SpriteCell;

/* Fields of a fixed-capacity block of SpriteCell records. */
#define SPRITE_CELL_LIST_CAPACITY 0x10 /* u16 cells in the block */
#define SPRITE_CELL_LIST_USED     0x12 /* u8 cells filled */
#define SPRITE_CELL_LIST_CELLS    0x14 /* SpriteCell * the cells */

/* Fields of the grid widget (CreateSpriteGrid), which embeds a cell list. */
#define SPRITE_GRID_VTABLE       0x00 /* void * class: gSpriteGridVTable */
#define SPRITE_GRID_ROWS         0x04 /* u8 rows of cells in the raster */
#define SPRITE_GRID_COLUMNS      0x05 /* u8 columns of cells in the raster */
#define SPRITE_GRID_CELL_WIDTH   0x06 /* u8 cell width in pixels */
#define SPRITE_GRID_CELL_HEIGHT  0x07 /* u8 cell height in pixels */
#define SPRITE_GRID_SELECTED     0x08 /* s16 item the cursor sits on */
#define SPRITE_GRID_ITEM_COUNT   0x0a /* s16 items the grid can scroll through */
#define SPRITE_GRID_SCROLL       0x0c /* s16 first visible row */
#define SPRITE_GRID_PIXEL_OFFSET 0x12 /* s16 animated offset of the scroll, in pixels */
#define SPRITE_GRID_BASE_X       0x14 /* s16 screen x of the first cell */
#define SPRITE_GRID_BASE_Y       0x16 /* s16 screen y of the first cell */
#define SPRITE_GRID_CELLS        0x18 /* SpriteCellList embedded in the widget */

#endif
