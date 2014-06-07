

#pragma once


typedef struct ZcCell
{
    int     mnRow;
    int     mnColumn;

} ZcCell;

typedef ZcArray<ZcCell> ZcCellArray;


typedef struct ZcCellRange
{
    int     mnTopRow;
    int     mnLeftColumn;
    int     mnBottomRow;
    int     mnRightColumn;

} ZcCellRange;

typedef ZcArray<ZcCellRange> ZcCellRangeArray;
