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

	ZcDbDatabase*		m_pFileDb;		//���������ݿ�
	ZcGePoint3d			m_pntMxbBlkIns; //��ϸ���������
	TitleArray			m_arrBtlData;	//���������ݼ�
	HDataTable			m_tblMxbData;	//��ϸ�����ݼ�
	ZcDbObjectIdArray	m_titleBlkRefIds;
	ZcDbObjectIdArray	m_bomBlkRefIds;
	ZcDbObjectIdArray	m_bomtitleBlkRefIds;
	CString				m_strDwgPath;	//����DWG·����
	CString				m_strTitle;		//�������ַ���
	CString				m_strBom;		//��ϸ���ַ���
	double				m_dblPlotScale;
	double				m_dblMxbBodyBlkRefHeight;
	bool				m_bIsCurDwg;	//������ǰ�򿪵�DWG��	
	bool				m_bIsForWrite;	//�Ƿ�д������

};