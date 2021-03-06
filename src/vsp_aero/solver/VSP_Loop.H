//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//
//////////////////////////////////////////////////////////////////////

#ifndef VSP_LOOP_H
#define VSP_LOOP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "utils.H"
#include "quat.H"

// Definition of the VSP_LOOP class

class VSP_LOOP {

private:

    // Loop based data

    int NumberOfNodes_;
    int *NodeList_;

    int NumberOfEdges_;
    int *EdgeList_;
    int *EdgeDirection_;

    // Upwind edge weights
   
    int *EdgeIsUpwind_;    
    double *EdgeUpwindWeight_;

    int SurfaceID_;
    int ComponentID_;
    int IsTrailingEdgeTri_;
    int IsLeadingEdgeTri_;
    int VortexLoop_;
    
    int SpanStation_;

    double Area_;
    
    double Length_;
    
    double RefLength_;
    
    double CentroidOffSet_;

    // Triangle Normal
    
    double Normal_[3];
    
    // Local Camber Line Normal
    
    double FlatPlateNormal_[3];

    // Centroid
    
    double XYZc_[3];
    
    // UV Centroid
    
    double UVc_[2];
    
    // Camber at centroid
    
    double Camber_;

    // Solution data
    
    double Gamma_;
    double dCp_;
    double dCp_Unsteady_;
    double Velocity_[3];
    double DownWash_Velocity_[3];    
    double Force_[3];
    double NormalForce_;
    double KTFact_;
    
    int SurfaceType_;
    int DegenBodyID_;
    int DegenWingID_;        
    int Cart3dID_;
    
    // Airfoil data

    double ThicknessToChord_;
    double LocationOfMaxThickness_;
    double RadiusToChord_;      
    
    // Agglomeration data
    
    int CoarseGridLoop_;
    
    int NumberOfFineGridLoops_;
    int *FineGridLoopList_;
    
    BBOX BoundBox_;
    
    int LoopUsed_;
    
    // Local free stream velocity
    
    double LocalFreeStreamVelocity_[5];

public:

    // Constructor, Destructor, Copy

    VSP_LOOP(void);
   ~VSP_LOOP(void);
    VSP_LOOP(const VSP_LOOP &VSPTri);
    VSP_LOOP& operator=(const VSP_LOOP &VSPTri);

    // Accesss to tri data

    void SizeNodeList(int NumberOfNodes);
    int NumberOfNodes(void) { return NumberOfNodes_; };
    int &Node1(void) { return NodeList_[0]; };
    int &Node2(void) { return NodeList_[1]; };
    int &Node3(void) { return NodeList_[2]; };
    int &Node4(void) { return NodeList_[3]; };
    int &Node(int i) { return NodeList_[i-1]; };

    // Access to edge data
    
    void SizeEdgeList(int NumberOfEdges);
    int NumberOfEdges(void) { return NumberOfEdges_;  };
    int &Edge1(void) { return EdgeList_[0]; };
    int &Edge2(void) { return EdgeList_[1]; };
    int &Edge3(void) { return EdgeList_[2]; };
    int &Edge4(void) { return EdgeList_[3]; };
    int &Edge(int i) { return EdgeList_[i-1]; };
    
    int &Edge1Direction(void) { return EdgeDirection_[0]; };
    int &Edge2Direction(void) { return EdgeDirection_[1]; };
    int &Edge3Direction(void) { return EdgeDirection_[2]; };
    int &Edge4Direction(void) { return EdgeDirection_[3]; };
    int &EdgeDirection(int i) { return EdgeDirection_[i-1]; };    
    
    int &Edge1IsUpWind(void) { return EdgeIsUpwind_[0]; };
    int &Edge2IsUpWind(void) { return EdgeIsUpwind_[1]; };
    int &Edge3IsUpWind(void) { return EdgeIsUpwind_[2]; };
    int &Edge4IsUpWind(void) { return EdgeIsUpwind_[3]; };
    int &EdgeIsUpWind(int i) { return EdgeIsUpwind_[i-1]; };

    double &Edge1UpwindWeight(void) { return EdgeUpwindWeight_[0]; };
    double &Edge2UpwindWeight(void) { return EdgeUpwindWeight_[1]; };
    double &Edge3UpwindWeight(void) { return EdgeUpwindWeight_[2]; };
    double &Edge4UpwindWeight(void) { return EdgeUpwindWeight_[3]; };
    double &EdgeUpwindWeight(int i) { return EdgeUpwindWeight_[i-1]; };
   
    int &SurfaceID(void) { return SurfaceID_; };
    int &ComponentID(void) { return ComponentID_; };    
    int &IsTrailingEdgeTri(void) { return IsTrailingEdgeTri_; };
    int &IsLeadingEdgeTri(void) { return IsLeadingEdgeTri_; };
    int &VortexLoop(void) { return VortexLoop_; };
    
    int &SpanStation(void) { return SpanStation_; };
    
    double &Area(void) { return Area_; };
    
    double &Length(void) { return Length_; };
    
    double &RefLength(void) { return RefLength_; };
    
    double &CentroidOffSet(void) { return CentroidOffSet_; };

    double &Nx(void) { return Normal_[0]; };
    double &Ny(void) { return Normal_[1]; };
    double &Nz(void) { return Normal_[2]; };
    double *Normal(void) { return Normal_; };

    double &NxFlatPlate(void) { return FlatPlateNormal_[0]; };
    double &NyFlatPlate(void) { return FlatPlateNormal_[1]; };
    double &NzFlatPlate(void) { return FlatPlateNormal_[2]; };
    double *FlatPlateNormal(void) { return FlatPlateNormal_; };
    
    double &Camber(void) { return Camber_; };
    
    double &Xc(void) { return XYZc_[0]; };
    double &Yc(void) { return XYZc_[1]; };
    double &Zc(void) { return XYZc_[2]; };
    double *xyz_c(void) { return XYZc_; };
    
    double &Uc(void) { return UVc_[0]; };
    double &Vc(void) { return UVc_[1]; };
    double *UVc(void) { return UVc_; };    
    
    double &U(void) { return Velocity_[0]; };
    double &V(void) { return Velocity_[1]; };
    double &W(void) { return Velocity_[2]; };
    
    double *Velocity(void) { return Velocity_; };
    
    double &DownWash_U(void) { return DownWash_Velocity_[0]; };
    double &DownWash_V(void) { return DownWash_Velocity_[1]; };
    double &DownWash_W(void) { return DownWash_Velocity_[2]; };
    
    double *DownWash_Velocity(void) { return DownWash_Velocity_; };

    double &Gamma(void) { return Gamma_; };
    double &dCp(void) { return dCp_; };
    double &dCp_Unsteady(void) { return dCp_Unsteady_; };
  
    double &Fx(void) { return Force_[0]; };
    double &Fy(void) { return Force_[1]; };
    double &Fz(void) { return Force_[2]; };
    double *Force(void) { return Force_; };
    
    double &NormalForce(void) { return NormalForce_; };
    
    double &KTFact(void) { return KTFact_; };
    
    int &SurfaceType(void) { return SurfaceType_; };
    int &DegenBodyID(void) { return DegenBodyID_; };
    int &DegenWingID(void) { return DegenWingID_; };    
    int &Cart3dID(void) { return Cart3dID_; };        
    
    // Airfoil data
    
    double &ThicknessToChord(void) { return ThicknessToChord_; };
    double &LocationOfMaxThickness(void ) { return LocationOfMaxThickness_; };
    double &RadiusToChord(void) { return RadiusToChord_; };    
        
    // Agglomeration data
    
    int &CoarseGridLoop(void) { return CoarseGridLoop_; };
    
    void SizeFineGridLoopList(int NumberOfLoops);    
    int  NumberOfFineGridLoops(void) { return NumberOfFineGridLoops_; };
    int &FineGridLoop(void) { return FineGridLoopList_[0]; };
    int &FineGridLoop(int i) { return FineGridLoopList_[i-1]; };
    
    BBOX &BoundBox(void) { return BoundBox_; };
    
    int &LoopUsed(void) { return LoopUsed_; };
   
    // Local free stream velocity
    
    double &LocalFreeStreamVelocity(int i) { return LocalFreeStreamVelocity_[i]; };
    double *LocalFreeStreamVelocity(void) { return LocalFreeStreamVelocity_; };
       
    void UpdateGeometryLocation(double *TVec, double *OVec, QUAT &Quat, QUAT &InvQuat);

};

#endif
