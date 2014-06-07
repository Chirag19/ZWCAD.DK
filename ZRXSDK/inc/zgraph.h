#ifndef ZD_GRAPH_H
#define ZD_GRAPH_H 1

#include "zdbmain.h"

#pragma pack (push, 8)

class ZcDbGraph;

class ZcDbGraphNode : public ZcHeapOperators
{
friend ZcDbGraph;

public:
    ZcDbGraphNode(void* pData = NULL);
    virtual ~ZcDbGraphNode();

    
    enum Flags    { kNone               = 0x00,
                    kVisited            = 0x01,   
                    kOutsideRefed       = 0x02,   
                    kSelected           = 0x04,  
                    kInList             = 0x08,  
                    kListAll            = 0x0E,  
                    kFirstLevel         = 0x10,  
                    kUnresTree          = 0x20,  
                    kAll                = 0x2F };
    void*               data            () const;
    void                setData         (void*);

    int                 numOut          () const;
    int                 numIn           () const;

    ZcDbGraphNode*      in              (int) const;
    ZcDbGraphNode*      out             (int) const;

    Zcad::ErrorStatus   addRefTo        (ZcDbGraphNode*);
    Zcad::ErrorStatus   removeRefTo     (ZcDbGraphNode*);
    Zcad::ErrorStatus   disconnectAll   ();

    ZcDbGraph*          owner           () const;

    bool                isMarkedAs      (Zdesk::UInt8 flags) const;
    Zcad::ErrorStatus   markAs          (Zdesk::UInt8 flags);
    Zcad::ErrorStatus   clear           (Zdesk::UInt8 flags);

    Zcad::ErrorStatus   markTree        (Zdesk::UInt8 flags,
                                         ZcDbVoidPtrArray* = NULL);

    int                 numCycleOut     () const;
    int                 numCycleIn      () const;

    ZcDbGraphNode*      cycleIn         (int) const;
    ZcDbGraphNode*      cycleOut        (int) const;

    ZcDbGraphNode*      nextCycleNode   () const;

    bool                isCycleNode     () const;

    void                setEdgeGrowthRate(int outEdgeRate, int inEdgeRate);

private:

   
    ZcDbGraphNode(const ZcDbGraphNode&);
    ZcDbGraphNode&      operator =      (const ZcDbGraphNode&);

    ZcDbVoidPtrArray    mOutgoing;
    ZcDbVoidPtrArray    mIncoming;

    void*               mpData;

    void                setFirstLevel   (Zdesk::Boolean);

    Zdesk::UInt8        mFlags;


    Zcad::ErrorStatus   setOwner        (ZcDbGraph*);
    Zcad::ErrorStatus   resetCycles     ();
    Zcad::ErrorStatus   removeCycleRefTo (ZcDbGraphNode*);
    Zcad::ErrorStatus   clearCycles     ();

    ZcDbGraph*          mpOwner;

    ZcDbVoidPtrArray*   mpCycleOut;
    ZcDbVoidPtrArray*   mpCycleIn;
};


class ZcDbGraph : public ZcHeapOperators
{
friend ZcDbGraphNode;

public:
    ZcDbGraph(ZcDbGraphNode* pRoot = NULL);
    virtual ~ZcDbGraph();

    ZcDbGraphNode*      node            (int index) const;
    ZcDbGraphNode*      rootNode        () const;

    int                 numNodes        () const;
    bool                isEmpty         () const;

    Zcad::ErrorStatus   addNode         (ZcDbGraphNode*);
    Zcad::ErrorStatus   addEdge         (ZcDbGraphNode* pFrom,
                                         ZcDbGraphNode* pTo);

    Zcad::ErrorStatus   delNode         (ZcDbGraphNode*);

    void                reset           ();
    void                clearAll        (Zdesk::UInt8 flags);

    void                getOutgoing     (ZcDbVoidPtrArray&);


    virtual Zdesk::Boolean findCycles   (ZcDbGraphNode* pStart = NULL);
    Zcad::ErrorStatus   breakCycleEdge  (ZcDbGraphNode* pFrom,
                                         ZcDbGraphNode* pTo);

    void                setNodeGrowthRate(int rate);

protected:

    Zcad::ErrorStatus   clearAllCycles  ();

private:

    
    ZcDbGraph(const ZcDbGraph&);
    ZcDbGraph&          operator =      (const ZcDbGraph&);

    ZcDbVoidPtrArray    mNodes;


    ZcDbVoidPtrArray*   mpCycleNodes;

    void                setDirty        ();
    bool                mDirty;

};


class ZcDbGraphStack : public ZcHeapOperators
{
public:
    ZcDbGraphStack(int initPhysicalLength = 0, int initGrowLength = 8);
    ~ZcDbGraphStack();

    Zcad::ErrorStatus   push            (ZcDbGraphNode*);
    ZcDbGraphNode*      pop             ();

    ZcDbGraphNode*      top             () const;

    bool                isEmpty         () const;

private:

    ZcDbVoidPtrArray    mStack;
};




#pragma pack (pop)

#endif

