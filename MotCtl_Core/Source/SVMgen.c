/*****************************************************************************
 * �ļ���: SVGEN.c
 *   �汾:
 *   ����: Hex
 *   ����: 2023.08.01
 *   ˵��: ��ɳ�ʼ������
 *****************************************************************************/

// **************************************************************************
// 	include files
// **************************************************************************
#include "SVM.h"

// **************************************************************************
// ȫ�ֱ�������  the globals
// **************************************************************************

// **************************************************************************
// ���캯��
// **************************************************************************

SVGEN_Handle SVGEN_init(void *pMemory, const size_t numBytes)
{
    SVGEN_Handle svgenHandle;

    if (numBytes < sizeof(SVGEN_Obj))
        return ((SVGEN_Handle)NULL);

    // ������
    svgenHandle = (SVGEN_Handle)pMemory;

    return (svgenHandle);
} // end of SVGEN_init()
