#include <Novice.h>
#include "Matrix4x4.h"

const char kWindowTitle[] = "LE2B_04_オオシマタイガ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 600, 500);

	Matrix4x4 m1 = {
		3.2f,0.7f,9.6f,4.4f,
		5.5f,1.3f,7.8f,2.1f,
		6.9f,8.0f,2.6f,1.0f,
		0.5f,7.2f,5.1f,3.3f
	};

	Matrix4x4 m2 = {
		4.1f,6.5f,3.3f,2.2f,
		8.8f,0.6f,9.9f,7.7f,
		1.1f,5.5f,6.6f,0.0f,
		3.3f,9.9f,8.8f,2.2f
	};

	Matrix4x4 resultAdd;
	Matrix4x4 resultMultiply;
	Matrix4x4 resultSubtract;
	Matrix4x4 inverseM1;
	Matrix4x4 inverseM2;
	Matrix4x4 transposeM1;
	Matrix4x4 transposeM2;
	Matrix4x4 identity;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		resultAdd = Add(m1, m2);
		resultMultiply = Multiply(m1, m2);
		resultSubtract = Subtract(m1, m2);
		inverseM1 = Inverse(m1);
		inverseM2 = Inverse(m2);
		transposeM1 = Transpose(m1);
		transposeM2 = Transpose(m2);
		identity = MakeIdentity4x4();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, 0, resultAdd, "Add");
		MatrixScreenPrintf(0, 5 * kRowHeight, resultSubtract, "Subtract");
		MatrixScreenPrintf(0, 5 * 2 * kRowHeight, resultMultiply, "Multiply");
		MatrixScreenPrintf(0, 5 * 3 * kRowHeight, inverseM1, "InverseM1");
		MatrixScreenPrintf(0, 5 * 4 * kRowHeight, inverseM2, "InverseM2");
		MatrixScreenPrintf(kColumnWidth * 5, 0, transposeM1, "TransposeM1");
		MatrixScreenPrintf(kColumnWidth * 5, 5 * kRowHeight, transposeM2, "TransposeM2");
		MatrixScreenPrintf(kColumnWidth * 5, 5 * 2 * kRowHeight, identity, "Identity");


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
