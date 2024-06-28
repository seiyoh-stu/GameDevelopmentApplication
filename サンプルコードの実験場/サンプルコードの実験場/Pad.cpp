#include "Pad.h"

#include "Pad.h"
#include <Dxlib.h>

namespace
{
	constexpr int kLogNum = 16;
	// ���̓��O 0���ŐV�̏��
	int padLog[kLogNum];
}

namespace Pad
{
	// �p�b�h�̓��͏�Ԏ擾
	void Update()
	{
		// ���݂̃p�b�h�̏�Ԃ��擾
		int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		// ���O�̍X�V
		for (int i = kLogNum - 1; i >= 1; i--)
		{
			padLog[i] = padLog[i - 1];
		}
		// �ŐV�̏��
		padLog[0] = padState;
	}

	// ������������
	bool IsPress(int button)
	{
		return (padLog[0] & button);
	}

	// �g���K�[����
	bool IsTrigger(int button)
	{
		bool isNow = (padLog[0] & button);	// ���݂̏��
		bool isLast = (padLog[1] & button);	// �P�t���[���O�̏��
		return (isNow && !isLast);
	}

	// ����������
	bool IsRelase(int button)
	{
		bool isNow = (padLog[0] & button);	// ���݂̏��
		bool isLast = (padLog[1] & button);	// �P�t���[���O�̏��
		return (!isNow && isLast);
	}
}