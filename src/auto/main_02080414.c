/* 34 functions from 0x02080414 to 0x02081400 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "fs.h"

/* Screen-flash callback: ease the screen brightness from normal (0) to white
 * (16) over the flash's fade-in frames, then continue the sprite's animation
 * once the last frame is reached. */
void StepScreenFlashFadeIn(void *sprite) {
 M2C_UNK Sprite_ResumeAnimation(void *); s8 EaseInterpolate(s32,s32,s32,s32,s32);
 extern void *gCur3DSpriteEngine;
 if(M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_IN_FRAMES)==0) {Sprite_ResumeAnimation(sprite);return;}
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_IN_ELAPSED)++;
 DS3D_BANK(gCur3DSpriteEngine)->brightness=EaseInterpolate(0,0,16,M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_IN_ELAPSED),M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_IN_FRAMES));
 if(M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_IN_ELAPSED)!=M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_IN_FRAMES)) return;
 Sprite_ResumeAnimation(sprite);
}

/* Screen-flash callback: hold the white screen for the flash's hold frames,
 * then continue the sprite's animation once the last frame is reached. */
void StepScreenFlashHold(void *sprite) {
 M2C_UNK Sprite_ResumeAnimation(void *);
 s32 elapsed;
 if(M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_HOLD_FRAMES)==0) {Sprite_ResumeAnimation(sprite);return;}
 elapsed=M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_HOLD_ELAPSED)+1;
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_HOLD_ELAPSED)=elapsed;
 if(elapsed!=M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_HOLD_FRAMES)) return;
 Sprite_ResumeAnimation(sprite);
}

/* Screen-flash callback: ease the screen brightness back from white (16) to
 * normal (0) over the flash's fade-out frames, then continue the sprite's
 * animation once the last frame is reached. */
void StepScreenFlashFadeOut(void *sprite) {
 M2C_UNK Sprite_ResumeAnimation(void *); s8 EaseInterpolate(s32,s32,s32,s32,s32);
 extern void *gCur3DSpriteEngine;
 if(M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_OUT_FRAMES)==0) {Sprite_ResumeAnimation(sprite);return;}
 M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_OUT_ELAPSED)++;
 DS3D_BANK(gCur3DSpriteEngine)->brightness=EaseInterpolate(0,16,0,M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_OUT_ELAPSED),M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_OUT_FRAMES));
 if(M2C_FIELD(sprite,s32 *,DS3D_SPRITE_FLASH_OUT_ELAPSED)!=M2C_FIELD(sprite,s16 *,DS3D_SPRITE_FLASH_OUT_FRAMES)) return;
 Sprite_ResumeAnimation(sprite);
}

/* Moves the 3D sprite engine(s) selected by target to (x, y) scaled by scale
 * percent: 0 moves both engines, 1 the current one, 2 the main one, 3 the sub
 * one, and 4 moves both engines' second offset pair instead. */
void Set3DSpriteOffset(s16 target, u16 scale, s32 x, s32 y) {
    s32 Divide(s32, s32);
    extern void *g3DSpriteEngineSub, *g3DSpriteEngineMain, *gCur3DSpriteEngine;
    s32 scaledX = Divide(x * scale, 100);
    s32 scaledY = Divide(y * scale, 100);
    switch (target) {
    case 0:
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_X) = scaledX;
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET_X) = M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_X);
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_Y) = scaledY;
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET_Y) = M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_Y);
        break;
    case 1:
        M2C_FIELD(gCur3DSpriteEngine, s16 *, DS3D_OFFSET_X) = scaledX;
        M2C_FIELD(gCur3DSpriteEngine, s16 *, DS3D_OFFSET_Y) = scaledY;
        break;
    case 2:
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET_X) = scaledX;
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET_Y) = scaledY;
        break;
    case 3:
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_X) = scaledX;
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET_Y) = scaledY;
        break;
    case 4:
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET2_X) = scaledX;
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET2_X) = M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET2_X);
        M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET2_Y) = scaledY;
        M2C_FIELD(g3DSpriteEngineMain, s16 *, DS3D_OFFSET2_Y) = M2C_FIELD(g3DSpriteEngineSub, s16 *, DS3D_OFFSET2_Y);
        break;
    }
}

/* Stop a screen-offset track: move the engine offsets it drives back to zero. */
void Clear3DSpriteOffset(DS3DSpriteOffsetTrack *track) {
    void Set3DSpriteOffset(s16, u16, M2C_UNK, M2C_UNK);
    Set3DSpriteOffset(track->target, track->scale, 0, 0);
}

/* Zero the engine offsets a screen-offset track drives and rewind it: its path
 * starts again at the first point with no points shown yet. */
void Reset3DSpriteOffsetTrack(DS3DSpriteOffsetTrack *track) {
    Set3DSpriteOffset(track->target, track->scale, 0, 0);
    track->index = 0;
    track->elapsed = 0;
}

/* Update callback of a screen-offset track sprite: move the tracked engine
 * offsets to the sprite's current path point and advance the point.  After the
 * last point the path starts over; once the track has shown its `steps` points
 * the object goes back to its regular animation. */
void Step3DSpriteOffsetPath(DS3DSpriteOffsetTrack *track) {
 M2C_UNK Sprite_ResumeAnimation(void *);
 s16 (*point)[2]=track->path;
 if(point[track->index][0]==0x7fff) {
 track->index=0;
 if(track->steps==-1){Sprite_ResumeAnimation(track);return;}
 }
 Set3DSpriteOffset(track->target,track->scale,point[track->index][0],point[track->index][1]);
 track->index++;
 track->elapsed++;
 if(track->elapsed!=track->steps)return;
 Sprite_ResumeAnimation(track);
}

/* Start a screen-offset effect: move both engines' second offset pair along
 * the screen-shake path `pathIndex` for `steps` points at full (100%) size,
 * using the sprite cloned from `source` (0 = the class's default mode). */
void CreateScreenOffsetEffect(s32 pathIndex, s32 steps, s32 source) {
    M2C_UNK Create3DSpriteOffsetTrack(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    Create3DSpriteOffsetTrack(4, pathIndex, steps, 0x64, source);
}

/* Create a screen-offset track sprite: a 3D sprite object of
 * g3DSpriteOffsetTrackClass (cloned from `source`, or the class's default mode
 * 6 when `source` is 0) that moves the engine offset pair `target` along path
 * `pathIndex`, scaled by `scale` percent, for `steps` points.  Returns the
 * object. */
M2C_UNK Create3DSpriteOffsetTrack(s32 target, s32 pathIndex, s32 steps, s32 scale, s32 source) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK g3DSpriteOffsetTrackClass;
    extern void *g3DSpriteOffsetTrackPaths[];
    void *object;
    DS3DSpriteOffsetTrack *track;

    if (source) object = CreateSpriteObject(&g3DSpriteOffsetTrackClass, source);
    else object = CreateSpriteFromClass(&g3DSpriteOffsetTrackClass, 6);
    track = (DS3DSpriteOffsetTrack *)object;
    track->path = g3DSpriteOffsetTrackPaths[pathIndex];
    track->steps = steps;
    track->target = target;
    track->scale = scale;
    return (M2C_UNK)object;
}

void Delete3DSpriteOffsetTracks(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK g3DSpriteOffsetTrackClass;
    DeleteSpriteObjectsOfClass(&g3DSpriteOffsetTrackClass);
}

#pragma opt_common_subs off
void DrawTilemapBlock(u8 *a,u16 *b,s32 c,s32 d) {
u16 v=(c&0x3ff)|((d&15)<<12);
s32 h=a[1]; s32 w=a[0]; u16 *p=(u16 *)(a+2); s32 x,y;
for(y=0;y<h;y++)for(x=0;x<w;x++) b[y*32+x]=v+*(p++);
}
#pragma opt_common_subs on
/* Fill a width x height rectangle of the 32-tile-wide `tilemap` with
 * consecutive tile numbers, starting from the low 10 bits of `startTile` and
 * taking the palette from `palette`. */
void FillTileRect(u16 *tilemap, s32 width, s32 height, u32 startTile, u16 palette) {
    s32 x, y;
    u16 tile = (startTile & 0x3ff) | ((palette & 15) << 12);
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
            tilemap[y * 32 + x] = tile++;
}

/* Replace the palette bank of every tile in a width x height rectangle of the
 * 32-tile-wide tilemap, keeping each tile's number and flip flags. */
void SetTileRectPalette(u16 *tilemap, s32 width, s32 height, u32 palette) {
    s32 x, y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
            tilemap[y * TILEMAP_ROW_TILES + x] =
                (tilemap[y * TILEMAP_ROW_TILES + x] & TILEMAP_ENTRY_INDEX_MASK) |
                ((palette & TILEMAP_PALETTE_MASK) << TILEMAP_PALETTE_SHIFT);
}

/* Add (palette & 15) to the palette index of every tile in a width x height
 * rectangle of the 32-tile-wide `tilemap`, wrapping the 4-bit index. */
void AddTileRectPalette(u16 *tilemap, s32 width, s32 height, u32 palette) {
    s32 x, y; u16 tile; u32 baseTile;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++) {
            tile = tilemap[y * 32 + x];
            baseTile = tile & 0xfff;
            tile ^= baseTile;
            tile += (palette & 15) << 12;
            tilemap[y * 32 + x] = baseTile | tile;
        }
}

/* Clear a width x height rectangle of tilemap words starting at tilemap,
 * walking the map's TILEMAP_ROW_TILES-tile rows. */
void ClearTileRect(u16 *tilemap, s32 width, s32 height) {
    s32 x, y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
            tilemap[y * TILEMAP_ROW_TILES + x] = 0;
}

/* Copy a width x height rectangle of tiles from one 32-tile-wide `tilemap`
 * to another, keeping every tile's number and flip flags. */
void CopyTileRect(u16 *dest, s32 width, s32 height, u16 *src) {
    s32 x, y;
    for (y = 0; y < height; y++)
        for (x = 0; x < width; x++)
            dest[y * TILEMAP_ROW_TILES + x] = src[y * TILEMAP_ROW_TILES + x];
}

#pragma opt_strength_reduction off
/* Fill a totalCols x totalRows tile rectangle of the 32-wide `tilemap` with
 * consecutive tile numbers, laid out column by column in chunkCols x chunkRows
 * chunks; tile numbers start at the low 10 bits of `startTile` and take the
 * palette from `palette`. */
void FillChunkedTileRect(u16 *tilemap, s32 totalCols, s32 totalRows, s32 chunkCols, u16 chunkRows, u16 startTile, u16 palette) {
    u16 *base;
    s32 y, x, row, stack;
    u16 cur = (u16)((startTile & 0x3ff) | ((palette & 0xf) << 12));
    y = 0;
    for (;y < totalRows;) {
        stack = 0;
        if (totalCols > 0) {
            do {
                row = 0;
                if ((s32)chunkRows > 0) {
                    do {
                        base = tilemap + stack;
                        x = 0;
                        if (chunkCols > 0) {
                            do {
                                base[(y+row)*32+x] = cur++;
                                x++;
                            } while (x < chunkCols);
                        }
                        row++;
                    } while (row < chunkRows);
                }
                stack += chunkCols;
            } while (stack < totalCols);
        }
        y += chunkRows;
    }
}
#pragma opt_strength_reduction reset
void func_02080b38(u16 *p,u32 w,s32 h){
 s32 y,x; u32 last=w-1;u16 tmp;u16 *a,*b;
 for(y=0;y<h;y++){
 for(x=0;x<(s32)(w>>1);x++){a=p+x;b=p+(last-x);tmp=a[y*32];a[y*32]=b[y*32];b[y*32]=tmp;}
 for(x=0;x<(s32)w;x++)p[y*32+x]^=0x400;
 }
}

/* Mount the card archive if needed, then move its FAT/FNT index tables into a
 * heap block: ask for the aligned size, allocate it, load the tables there. */
void LoadCardArchiveIndexToHeap(void) {
    M2C_UNK InitCardArchiveOnce(M2C_UNK);
    s32 LoadCardArchiveIndex(s32, s32);
    s32 HeapAllocBlock();
    s32 indexSize;

    InitCardArchiveOnce(-1);
    indexSize = LoadCardArchiveIndex(0, 0);
    LoadCardArchiveIndex(HeapAllocBlock(), indexSize);
}

/* Return the size in bytes of the file at `path`, or 0 when it cannot be
 * opened.  A temporary filesystem request is opened and closed around the size. */
s32 GetFileSize(void *path) {
 void InitFileRequest(void *);s32 OpenFileRequest(void *,void *);void CloseFileRequest(void *);
 void *request[18];s32 size;
 InitFileRequest(request);
 if(!OpenFileRequest(request,path))return 0;
 size=M2C_FIELD(request,u32 *,FS_REQ_FILE_END)-M2C_FIELD(request,u32 *,FS_REQ_FILE_START);CloseFileRequest(request);return size;
}

/* Reads the whole file at `path` into memory at `dest` in 0x2800-byte chunks and
 * returns its size. Halts the system and returns 0 if the file cannot be opened
 * or a read comes back short. */
int LoadFileToAddress(void *path, void *dest) {
    void *req[18];
    int off;
    int total;
    int chunk;

    InitFileRequest(req);
    if (OpenFileRequest(req, path) == 0) {
        SystemHalt();
        return 0;
    }
    total = (int)M2C_FIELD(req, u32 *, FS_REQ_FILE_END) - (int)M2C_FIELD(req, u32 *, FS_REQ_FILE_START);
    off = 0;
    if (total != 0) {
        do {
            chunk = total - off;
            if ((unsigned int)chunk >= 0x2800) {
                chunk = 0x2800;
            }
            if (FileRead(req, (char *)dest + off, chunk) != chunk) {
                SystemHalt();
                return 0;
            }
            off += chunk;
        } while (total - off != 0);
    }
    CloseFileRequest(req);
    return total;
}

/* Read the compressed file at `path` in 0x2000-byte chunks and decompress it to the
 * address `dest` (which selects RAM or VRAM).  Returns the decompressed size, or 0
 * after halting the system if a read fails. */
s32 LoadDecompressedFileTo(void *path, s32 dest) {
    int InitFileRequest(void *);
    int OpenFileRequest(void *, void *);
    int FileRead(void *, void *, s32);
    int CloseFileRequest(void *);
    int SystemHalt(void);
    int HeapAllocBlockTail(s32);
    int HeapFreeBlock(s32);
    u32 InitDecompress(void *, void *, u32);
    s32 DecompressChunk(void *, void *, s32);

    int req[18];
    u8 decoder[0x220];

    s32 read = 0;
    void *buf;
    u32 fileSize;
    u32 chunk;
    u32 size;
    u32 next;
    int maxChunk;

    buf = (void *)HeapAllocBlockTail(0x2000);

    InitFileRequest(req);
    if (OpenFileRequest(req, path) == 0) {
        SystemHalt();
        return read;
    }

    fileSize = (u32)(req[10] - req[9]);

    if (fileSize < 0x2000U) {
        chunk = fileSize;
    } else {
        chunk = 0x2000U;
    }

    if (FileRead(req, buf, (s32)chunk) != (s32)chunk) {
        SystemHalt();
        return 0;
    }

    read += (s32)chunk;
    size = InitDecompress(decoder, buf, (u32)dest);

    if (DecompressChunk(decoder, (void *)((char *)buf + 4), (s32)chunk - 4) > 0) {
        do {
            maxChunk = 0x2000;
            next = fileSize - (u32)read;
            if (next >= 0x2000U) {
                next = (u32)maxChunk;
            }
            if (FileRead(req, buf, (s32)next) != (s32)next) {
                SystemHalt();
                return 0;
            }
            read += (s32)next;
        } while (DecompressChunk(decoder, buf, (s32)next) > 0);
    }

    CloseFileRequest(req);
    HeapFreeBlock((int)buf);
    return (s32)size;
}

/* Reads the whole file at `path` into a newly allocated buffer of exactly the
 * file's size, in 0x2800-byte chunks, and returns it. A nonzero `persistent`
 * takes the buffer from the permanent asset heap instead of the temporary one.
 * Returns 0 after halting the system if the file cannot be opened or a read
 * fails. */
void *LoadFileToBuffer(void *path, int persistent) {
    void *req[18];
    int off;
    int total;
    void *buf;
    int chunk;
    int start;
    int end;

    InitFileRequest(req);
    if (OpenFileRequest(req, path) == 0) {
        SystemHalt();
        return 0;
    }
    end = (int)req[10];
    start = (int)req[9];
    total = end - start;
    if (persistent != 0) {
        buf = (void *)HeapAllocBlock(total);
    } else {
        buf = (void *)HeapAllocBlockTail(total);
    }
    off = 0;
    if (total != 0) {
        do {
            chunk = total - off;
            if ((unsigned int)chunk >= 0x2800) {
                chunk = 0x2800;
            }
            if (FileRead(req, (void *)((char *)buf + off), chunk) != chunk) {
                SystemHalt();
                return 0;
            }
            off += chunk;
        } while (total - off != 0);
    }
    CloseFileRequest(req);
    return buf;
}

/* Loads the compressed file at `path`, decompresses it into a freshly allocated
   buffer and returns that buffer, writing the decompressed size through outSize.
   A nonzero `persistent` takes the buffers from the permanent asset heap instead
   of the temporary block heap. */
s32 LoadDecompressedFileBuffer(s32 path,s32 persistent,s32 outSize) {
s32 HeapAllocBlockTail(s32);s32 HeapAllocBlock();s32 HeapFreeBlock(s32);
s32 InitFileRequest(void *);s32 OpenFileRequest(void *,void *);s32 FileRead(void *,void *,s32);s32 CloseFileRequest(void *);s32 SystemHalt(void);
s32 GetDecompressedSize(void *);u32 InitDecompress(void *, void *, u32);s32 DecompressChunk(void *,void *,s32);
u32 req[18];u8 decoder[0x220]; s32 size; s32 output; u8 *buf; u32 read=0; u32 total,chunk;
if(persistent)buf=(u8 *)HeapAllocBlockTail(0x2000);else buf=(u8 *)HeapAllocBlock(0x2000);
InitFileRequest(req);
if(!OpenFileRequest(req,(void *)path)){SystemHalt();return 0;}
total=req[10]-req[9];chunk=total<0x2000?total:0x2000;
if(FileRead(req,buf,chunk)!=chunk){SystemHalt();return 0;}
read+=chunk;
size=GetDecompressedSize(buf);
if(persistent)output=HeapAllocBlock(size);else output=HeapAllocBlockTail(size);
InitDecompress(decoder,buf,(void *)output);
if(DecompressChunk(decoder,buf+4,chunk-4)>0) { u32 next; do {
next=total-read;if(next>=0x2000)next=0x2000;
if(FileRead(req,buf,next)!=next){SystemHalt();return 0;}
read+=next;
}while(DecompressChunk(decoder,buf,next)>0); }
CloseFileRequest(req);HeapFreeBlock((s32)buf);if(outSize)*(s32 *)outSize=size;
return output;
}

void LoadDecompressedFile(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK LoadDecompressedFileBuffer(M2C_UNK, M2C_UNK, M2C_UNK);
    LoadDecompressedFileBuffer(arg0, arg1, 0);
}

/* Open the file at `path`, seek to `offset` and read `size` bytes into `dest`.
 * Halts the system and returns 0 if the file cannot be opened, the seek fails or
 * the read comes back short; returns 1 on success. */
int ReadFileSection(int path, int dest, int offset, int size) {
    void *req[18];

    InitFileRequest(req);
    if (OpenFileRequest(req, path) == 0) {
        SystemHalt();
        return 0;
    }
    if (FileSeek(req, offset, 0) == 0) {
        SystemHalt();
        return 0;
    }
    if (FileRead(req, dest, size) != size) {
        SystemHalt();
        return 0;
    }
    CloseFileRequest(req);
    return 1;
}

/* Read the file at `path` into a freshly allocated `size`-byte buffer from the
 * game heap.  Returns the buffer, or NULL after freeing it when the file cannot
 * be read. */
s32 LoadFileToNewBuffer(M2C_UNK path, M2C_UNK size) {
    s32 ReadFileSection(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    s32 HeapAllocBlockTail(M2C_UNK);
    s32 buffer = HeapAllocBlockTail(size);
    if (ReadFileSection(path, buffer, 0, size)) return buffer;
    HeapFreeBlock(buffer);
    return 0;
}

/* Load the file `path` into the current 3D sprite engine's OBJ palette shadow at
 * byte `offset`, then mark the palette dirty so it is uploaded on the next
 * flush. Returns 0 when the file could not be read. */
s32 LoadFileToSpriteBuffer(M2C_UNK path, s32 offset, M2C_UNK size) {
    s32 ReadFileSection(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;

    if (ReadFileSection(path, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_PALETTES) + offset, 0, size) == 0) {
        return 0;
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) | DS3D_DIRTY_PALETTE);
    return 1;
}

/* Loads a file into the BG extended palette of the current 3D sprite engine:
 * the main engine's palette at the given 8 KB slot when the main engine is
 * current, the sub engine's palette otherwise. */
s32 LoadFileToBGExtPltt(M2C_UNK path, s32 paletteSlot, s32 offset, s32 size) {
 M2C_UNK GX_BeginLoadBGExtPltt(void); M2C_UNK GX_LoadBGExtPltt(s32,s32,s32); M2C_UNK GX_EndLoadBGExtPltt(void);
 M2C_UNK GX_BeginLoadBGExtPlttSub(void); M2C_UNK GX_LoadBGExtPlttSub(s32,s32,s32); M2C_UNK GX_EndLoadBGExtPlttSub(void);
 extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain;
 s32 buffer; s32 isMainEngine;
 buffer=LoadFileToNewBuffer(path,size);
 if(buffer==0) return 0;
 DC_FlushRange(buffer,size);
 if(gCur3DSpriteEngine==g3DSpriteEngineMain) isMainEngine=1; else isMainEngine=0;
 if(isMainEngine & 0xFF) {GX_BeginLoadBGExtPltt();GX_LoadBGExtPltt(buffer,offset+(paletteSlot<<13),size);GX_EndLoadBGExtPltt();}
 else {GX_BeginLoadBGExtPlttSub();GX_LoadBGExtPlttSub(buffer,offset+(paletteSlot<<13),size);GX_EndLoadBGExtPlttSub();}
 HeapFreeBlock(buffer); return 1;
}

/* Load the file at `path` and queue an upload of its `size` bytes into the BG
 * extended palette at byte `offset`, `paletteSlot` (0x2000 bytes each) further
 * into it; the file buffer is freed after the upload.  Returns 1, or 0 when the
 * file could not be read. */
s32 QueueFileToBGExtPltt(M2C_UNK path, M2C_UNK paletteSlot, M2C_UNK offset, M2C_UNK size) {
    M2C_UNK QueueBGExtPaletteUpload(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 LoadFileToNewBuffer(M2C_UNK, M2C_UNK);
    s32 buffer;

    buffer = LoadFileToNewBuffer(path, size);
    if (buffer == 0) {
        return 0;
    }
    QueueBGExtPaletteUpload(buffer, paletteSlot, offset, size, 1);
    return 1;
}

/* Loads a file into the OBJ (sprite) extended palette of the current 3D sprite
 * engine: the main engine's palette at the given 8 KB slot when the main engine
 * is current, the sub engine's palette otherwise. */
s32 LoadFileToOBJExtPltt(M2C_UNK path, s32 paletteSlot, s32 offset, s32 size) {
 M2C_UNK GX_BeginLoadOBJExtPltt(void); M2C_UNK GX_LoadOBJExtPltt(s32,s32,s32); M2C_UNK GX_EndLoadOBJExtPltt(void);
 M2C_UNK GX_BeginLoadOBJExtPlttSub(void); M2C_UNK GX_LoadOBJExtPlttSub(s32,s32,s32); M2C_UNK GX_EndLoadOBJExtPlttSub(void);
 extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain;
 s32 buffer; s32 isMainEngine;
 buffer=LoadFileToNewBuffer(path,size);
 if(buffer==0) return 0;
 DC_FlushRange(buffer,size);
 if(gCur3DSpriteEngine==g3DSpriteEngineMain) isMainEngine=1; else isMainEngine=0;
 if(isMainEngine & 0xFF) {GX_BeginLoadOBJExtPltt();GX_LoadOBJExtPltt(buffer,offset+(paletteSlot<<13),size);GX_EndLoadOBJExtPltt();}
 else {GX_BeginLoadOBJExtPlttSub();GX_LoadOBJExtPlttSub(buffer,offset+(paletteSlot<<13),size);GX_EndLoadOBJExtPlttSub();}
 HeapFreeBlock(buffer); return 1;
}

/* Load `size` bytes at `fileOffset` of the file at `path` into the current 3D
 * sprite engine's OBJ palette shadow at byte `destOffset`, then mark the palette
 * dirty so it is uploaded on the next flush.  Returns 0 when the file could not be
 * read. */
s32 LoadFileSectionToSpriteBuffer(M2C_UNK path, s32 destOffset, M2C_UNK fileOffset, M2C_UNK size) {
    s32 ReadFileSection(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;

    if (!ReadFileSection(path, M2C_FIELD(gCur3DSpriteEngine, s32 *, DS3D_ENGINE_PALETTES) + destOffset, fileOffset, size)) return 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_PALETTE;
    return 1;
}

/* Load the decompressed file at `path` and upload its bytes into the texture
 * bank at byte `destOffset`, then release the buffer.  Returns the number of
 * bytes loaded. */
s32 LoadFileToTextureBank(M2C_UNK path, M2C_UNK destOffset) {
    M2C_UNK UploadTextureBank(s32, M2C_UNK, s32);
    M2C_UNK HeapFreeBlock(s32);
    s32 size;
    s32 buffer;

    buffer = LoadDecompressedFileBuffer(path, 0, &size);
    DC_FlushRange(buffer, size);
    UploadTextureBank(buffer, destOffset, size);
    HeapFreeBlock(buffer);
    return size;
}

/* Decompress the file at `path` into a buffer and queue a copy of it into the
 * texture bank at byte `destOffset`; the queued copy frees the buffer once it has
 * been uploaded.  Returns the number of bytes loaded. */
s32 QueueFileToTextureBank(M2C_UNK path, M2C_UNK destOffset) {
    M2C_UNK DC_FlushRange(s32, s32);
    M2C_UNK QueueTextureBankCopy(s32, M2C_UNK, s32, M2C_UNK);
    s32 size;
    s32 buffer;

    buffer = LoadDecompressedFileBuffer(path, 0, &size);
    DC_FlushRange(buffer, size);
    QueueTextureBankCopy(buffer, destOffset, size, 1);
    return size;
}

