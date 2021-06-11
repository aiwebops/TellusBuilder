/* -*-c++-*- StereoV3D - Copyright (C) 2021.
* Author	: Ethan Li<ethan.li.whu@gmail.com>
* https://github.com/ethan-li-coding/StereoV3DCode
*/

#ifndef SV3D_EIGEN_DEFS_H
#define SV3D_EIGEN_DEFS_H

#include <Eigen/Core>
#include <Eigen/Dense>
using namespace Eigen;

namespace sv3d
{
	// 3d ʸ�� (double����)
	using Vec2 = Eigen::Vector2d;
		
	/// 2d ʸ�� (float����)
	using Vec2f = Eigen::Vector2f;
	
	// 3d ʸ�� (double����)
	using Vec3 = Eigen::Vector3d;

	// 3d ʸ�� (float����)
	using Vec3f = Eigen::Vector3f;

	/// 4d ʸ�� 
	using Vec4 = Eigen::Vector4d;
	
	// 9d ʸ��
	using Vec9 = Eigen::Matrix<double, 9, 1>;
	
	// 3x3 ���� (double����)
	using Mat3 = Eigen::Matrix<double, 3, 3>;
		
	// 3x4 ���� (double����)
	using Mat34 = Eigen::Matrix<double, 3, 4>;
	
	// 3x3 ���� (double����)��������
	using RMat3 = Eigen::Matrix<double, 3, 3, Eigen::RowMajor>;

	// 3x4 ���� (double����)
	using RMat34 = Eigen::Matrix<double, 3, 4, Eigen::RowMajor>;

	// 4x4 ���� (double����)
	using Mat4 = Eigen::Matrix<double, 4, 4>;
	
	// 2xN ���� (double����)
	using Mat2X = Eigen::Matrix<double, 2, Eigen::Dynamic>;
		
	// 3xN ���� (double����)
	using Mat3X = Eigen::Matrix<double, 3, Eigen::Dynamic>;

	// Nx9 ���� (double����)
	using MatX9 = Eigen::Matrix<double, Eigen::Dynamic, 9>;

	// Nx9 ���� (double����)��������
	using RMatX9 = Eigen::Matrix<double, Eigen::Dynamic, 9, Eigen::RowMajor>;

	// NxM ���� (double����)
	using MatXX = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>;

	// NxM ���� (double����)��������
	using RMatXX = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;
}

#endif