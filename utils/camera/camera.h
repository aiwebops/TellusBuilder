/* -*-c++-*- StereoV3D - Copyright (C) 2021.
* Author	: Ethan Li<ethan.li.whu@gmail.com>
* https://github.com/ethan-li-coding/StereoV3DCode
* Describe	: header of camera class
*/

#ifndef SV3D_CAMERA_H
#define SV3D_CAMERA_H

#include "../eigen_defs.h"

namespace sv3d
{
	// �����ģ��ͨ����ʽ����
	//   P = K[R,t]
	// ����R��t��ʾ����������������ϵ����̬��ƽ��
	// R Ϊ�������ϵ�������������ϵ����ת����
	// t Ϊ�������ϵ�������������ϵ��ƽ��ʸ��
	// �������ϵ����������ϵ��Ϊ����ϵ
	class Camera {
	public:
		Mat3	K_;			// �ڲξ���
		Mat3	R_;			// ��ת����
		Vec3	t_;			// ƽ�ƾ���
		Mat34	P_;			// ͶӰ����
		Mat3	KI_;		// �ڲξ���������
		Mat3	RT_;		// ��ת����������

	public:
		inline Camera() = default;
		inline ~Camera() = default;

		/** ͨ��K��R��t�����������ע�����������ƶ�������⸴�Ʋ���������Ĳ�����ִ�й��캯�����ڴ����� */
		inline Camera(Mat3 K, Mat3 R, Vec3 t) : K_(std::move(K)), R_(std::move(R)), t_(std::move(t)) {
			KI_ = K_.inverse();
			RT_ = R_.transpose();
			P_ << K_ * R_, K_* t_;
		}

		/*****************************************����������ϵת���ӿ�*****************************************/
		/** �������ϵת������������ϵ */
		inline Vec3 TransformPointC2W(const Vec3& X) const {
			return R_.transpose() * (X - t_);
		}
		/** ��������ϵ���������ϵ */
		inline Vec3 TransformPointW2C(const Vec3& X) const {
			return R_ * X + t_;
		}
		/** �������ϵ��Ӱ������ϵ */
		inline Vec2 TransformPointC2I(const Vec3& X) const {
			auto I = Vec3(K_ * X);
			return Vec2(I[0] / I[2], I[1] / I[2]);
		}
		/** ��������ϵ��Ӱ������ϵ */
		inline Vec2 TransformPointW2I(const Vec3& X) const {
			return TransformPointC2I(TransformPointW2C(X));
		}
		/**  Ӱ������ϵת�����������ϵ(�����֪��X[2]) */
		inline Vec3 TransformPointI2C(const Vec3& X) const {
			auto Xt = X;
			Xt[0] *= Xt[2]; Xt[1] *= Xt[2];
			return KI_ * Xt;
		}
		/**  Ӱ������ϵת������������ϵ(�����֪��X[2]) */
		inline Vec3 TransformPointI2W(const Vec3& X) const {
			return TransformPointC2W(TransformPointI2C(X));
		}
		/*****************************************����������ϵת���ӿ�*****************************************/

	};
}

#endif