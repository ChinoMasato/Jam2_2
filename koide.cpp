//1��ځ@�i���{���j
if (Question[i].num == 0)
{
	//��蕶
	Question[i].sentence[0] = "��t�����͔|������{���ŁA";
	Question[i].sentence[1] = "�����悻�̎��n������";
	Question[i].sentence[2] = "�V�����{����W�����{�܂ł�";
	Question[i].sentence[3] = "�i��͎��̂����ǂ�H";

	Question[i].Image_Graphic = LoadGraph("");//���̃C���[�W�摜��ϐ��ɓǂݍ���

	//�I����
	Question[i].choices[0] = "A�F�K��";
	Question[i].choices[1] = "B�F�L��";
	Question[i].choices[2] = "C�F������";
	Question[i].choices[3] = "D�F�H����";

	//�����iA�AB�AC�AD�̂ǂꂩ����́j
	Question[i].answer = 'A';

	//���̉��
	Question[i].tips[0] = "��t���̓��{���́A";
	Question[i].tips[1] = "�Y�o�z�A�͔|�ʐρA���n�ʂ��P�ʂł��B";
}

//2��ځ@�i暐����j
if (Question[i].num == 1)
{
	//��蕶
	Question[i].sentence[0] = "�؍X�Îs��暐����ɓ`���`���́A";
	Question[i].sentence[1] = "�u���{�O�偡�`���v�̂ЂƂƂ��ėL���B";
	Question[i].sentence[2] = "���ɓ��铮���́A���̂����ǂ�H";

	Question[i].Image_Graphic = LoadGraph("");//���̃C���[�W�摜��ϐ��ɓǂݍ���

	//�I����
	Question[i].choices[0] = "A�F��";
	Question[i].choices[1] = "B�F��";
	Question[i].choices[2] = "C�F�K";
	Question[i].choices[3] = "D�F�l��";

	//�����iA�AB�AC�AD�̂ǂꂩ����́j
	Question[i].answer = 'C';

	//���̉��
	Question[i].tips[0] = "暐����́u�K���q�`���v�����Ƃ���";
	Question[i].tips[1] = "�u暐����̒K���q�v�Ƃ������w������܂��B";
}
