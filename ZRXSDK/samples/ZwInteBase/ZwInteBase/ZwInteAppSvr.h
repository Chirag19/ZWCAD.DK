#pragma once

class ZwInteAppSvr
{
public:
	ZwInteAppSvr(LPCTSTR dwgPathName,bool bIsForWrite = false);
	virtual ~ZwInteAppSvr(void);

	void initializeTitle(LPCTSTR strTitle);
	void initializeBom(LPCTSTR strBom);
	TitleArray*	getTitleData();	
	HDataTable*	getBomData();
	void setTitleData();	
	void setBomData();
	void save();
	CString getDwgPath();

private:
	void initializeTitleForRead();
	void initializeBomForRead();
	void initializeTitleForWrite();
	void initializeBomForWrite();
	bool getTbBlkRefIds();
	bool getPlotScale();
	bool getMxbBlkInsPt();

	ZcDbDatabase*		m_pFileDb;		//操作的数据库
	ZcGePoint3d			m_pntMxbBlkIns; //明细表块插入基点
	TitleArray			m_arrBtlData;	//标题栏数据集
	HDataTable			m_tblMxbData;	//明细表数据集
	ZcDbObjectIdArray	m_titleBlkRefIds;
	ZcDbObjectIdArray	m_bomBlkRefIds;
	ZcDbObjectIdArray	m_bomtitleBlkRefIds;
	CString				m_strDwgPath;	//操作DWG路径名
	CString				m_strTitle;		//标题栏字符集
	CString				m_strBom;		//明细表字符集
	double				m_dblPlotScale;
	double				m_dblMxbBodyBlkRefHeight;
	bool				m_bIsCurDwg;	//操作当前打开的DWG？	
	bool				m_bIsForWrite;	//是否写操作？

};