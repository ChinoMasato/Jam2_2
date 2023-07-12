//6問目（大根）
if (Question[i].num == 5)
{
	//問題文
	Question[i].sentence[0] = "次のうち、千葉県での生産量が";
	Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：いちじく";
	Question[i].choices[1] = "B：ぶり類";
	Question[i].choices[2] = "C：メロン";
	Question[i].choices[3] = "D：大根";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'D';

	//問題の解説
	Question[i].tips[0] = "国内産の落花生の8割は、";
	Question[i].tips[1] = "千葉県で生産されています。";
}
//7問目（龍角寺）
if (Question[i].num == 6)
{
	//問題文
	Question[i].sentence[0] = "千葉県の印旛沼付近に伝えられている";
	Question[i].sentence[1] = "龍伝承では、龍の体が３つに裂けて";
	Question[i].sentence[2] = "それぞれが落ちた場所に、";
	Question[i].sentence[3] = "龍腹寺、龍尾寺ができた。";
	Question[i].sentence[4] = "あと一つは？";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：龍頭寺";
	Question[i].choices[1] = "B：龍焔寺";
	Question[i].choices[2] = "C：龍角寺";
	Question[i].choices[3] = "D：龍牙寺";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'C';

	//問題の解説
	Question[i].tips[0] = "龍角寺は千葉県印旛郡栄町に";
	Question[i].tips[1] = "あり、７世紀以上前に創建";
	Question[i].tips[2] = "された、関東屈指の古寺です。";
}
//8問目（落花生）
if (Question[i].num == 7)
{
	//問題文
	Question[i].sentence[0] = "次のうち、千葉県での生産量が";
	Question[i].sentence[1] = "日本一である野菜・農作物はどれ？";

	Question[i].Image_Graphic = LoadGraph("");//問題のイメージ画像を変数に読み込む

	//選択肢
	Question[i].choices[0] = "A：Apple社";
	Question[i].choices[1] = "B：落花生";
	Question[i].choices[2] = "C：ふなっしー";
	Question[i].choices[3] = "D：すいか";

	//正解（A、B、C、Dのどれかを入力）
	Question[i].answer = 'B';

	//問題の解説
	Question[i].tips[0] = "国内産の落花生の8割は、";
	Question[i].tips[1] = "千葉県で生産されています。";
}