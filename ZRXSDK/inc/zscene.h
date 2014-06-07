#ifndef ZD_SCENE_H
#define ZD_SCENE_H


#include "ZdZChar.h"

#pragma pack (push, 8)


#define FACEVER  0                    
#define         HEADER          'H'
#define         ENTITY          'E'
#define         EVERTEX         'V'
#define         POLYGON         'P'
#define         CONTOUR         'X'
#define         SHADER          'D'
#define         CMESH           'H'
#define         BLOCK_B         'U'     
#define         BLOCK_E         'O'     
#define         E_LAYER         'L'     



#define         TOPBOT          0x2



#define ENT_HAS_CMESH  1               
#define ENT_HAS_XFORM  2               
#define ENT_HAS_XDATA  4               
#define ENT_HAS_NORMAL 8               
#define ENT_HAS_SUBENT 16              
 

#define RENDER_CACHE      1
 

struct zscn_cmesh {
    char   id;
    short  flags;
    long   next;
    short  mshtype;
    short  color;
    short  nverts;
    short  m;
    short  n;
};



struct zscn_vrtc {
    char   id;
    double vert[3];                  
};



struct zscn_pmsh {
    char   id;
    short  flags;                     
#ifndef _WIN64
    long   adr1;                      
    long   adr2;                      
#else
    __int64  adr1;
    __int64  adr2;
#endif
    long   layerindex;                
    short  color;                     
    long   truecolor;                 
    short  ncvrtx;                    
#ifndef _WIN64
    long   mapperId;                  
#else
    __int64  mapperId;
#endif
};



struct zscn_cvrt {
    char   id;
    long   index;                     
};



struct zscn_node {
    double vertex[3];                   
    double normal[3];                   
    long left;                        
    long right;                       
};



#define CMAPSIZE 32

struct ze2f_hdr {                   
    char id;                          
    short flags;                      
    short version;                    
    long nents;                       
    long npoly;                       
    long nlayers;                     
    unsigned long bgcolor;            
    short cmaplen;                    
    char *cmap;                       
};


 
struct ze2f_layer {                
    char id;                        
    short layernamelen;       
    ZCHAR *lname;                    
};
 


struct ze2f_ent {                 
    char id;                      
    short flags;                  
    short type;                       
#ifndef _WIN64
    long  adr1;                       
    long  adr2;                      
#else
    __int64  adr1;
    __int64  adr2;
#endif
    long  npoly;                 
    long  nverts;                     
    short color;                    
    long  truecolor;              
    long  layerindex;               
                                   
#ifndef _WIN64
    long  materialId;             
#else
    __int64 materialId;
#endif
};

 
struct ze2f_xform {              
    char id;                         
    short flags;                    
    double xfmatrix[4][4];             
};



extern struct ze2f_hdr   ze2fheader;    
extern struct ze2f_ent   ze2fentity;  
extern struct ze2f_layer ze2flayer;     
extern struct ze2f_xform ze2fxform;     
extern struct zscn_vrtc  zvrtcr;       
extern struct zscn_cvrt  zcvrtr;        
extern struct zscn_pmsh  zpmshr;        



#ifdef RENDERDATA

typedef double zdwg3dp[3];

class ZcReCallout {
    public :
      virtual void e2fHeaderData(struct ze2f_hdr *hdr) { };
      virtual void e2fLayerData(struct ze2f_layer *lyr) { };
      virtual void e2fBlockData(struct ze2f_ent *ent,
                                struct ze2f_xform *xform) { };
      virtual void e2fEntityData(struct ze2f_ent *ent) { };
      virtual void e2fVertexData(zdwg3dp *vertex_array) { };
      virtual void e2fNormalData(zdwg3dp *normals_array) { };
      virtual void e2fMeshData(struct zscn_pmsh *polymesh,
                               long **polyindex) { };
   
      int flag;

};


int zcreRegisterCallout(ZcReCallout * imp);

Zcad::ErrorStatus zcreEntityToFaces(zds_name ss, ZCHAR** const name, int normal);

#endif 

#pragma pack (pop)
#endif 
