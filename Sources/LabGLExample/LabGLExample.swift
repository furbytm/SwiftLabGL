import LabGL

@main
struct LabGLExample
{
  static func main()
  {
    LABGLDISPATCH_glViewport(0, 0, 800, 600)
    
    LABGLDISPATCH_glClearColor(0.1, 0.1, 0.15, 1.0)
    LABGLDISPATCH_glClear(UInt32(GL_COLOR_BUFFER_BIT))
    
    LABGLDISPATCH_glEnable(UInt32(GL_PBR_MODE))
    LABGLDISPATCH_glMaterialf(UInt32(GL_FRONT_AND_BACK), UInt32(GL_METALLIC),  0.0)
    LABGLDISPATCH_glMaterialf(UInt32(GL_FRONT_AND_BACK), UInt32(GL_ROUGHNESS), 0.6)
    LABGLDISPATCH_glMaterialf(UInt32(GL_FRONT_AND_BACK), UInt32(GL_OCCLUSION), 1.0)
    
    lglSetIBLDiffuseSGs(0, nil)
    lglSetIBLSpecularSGs(0, nil)
    lglSetIBLReflectionCube(1, 0)

    gl.begin(mode: UInt32(GL_TRIANGLES)) // renamed from LABGLDISPATCH_glBegin in LabGL.apinotes
    LABGLDISPATCH_glColor3f(1.0, 0.0, 0.0); LABGLDISPATCH_glVertex2f(-0.5, -0.5)
    LABGLDISPATCH_glColor3f(0.0, 1.0, 0.0); LABGLDISPATCH_glVertex2f( 0.5, -0.5)
    LABGLDISPATCH_glColor3f(0.0, 0.0, 1.0); LABGLDISPATCH_glVertex2f( 0.0,  0.5)
    LABGLDISPATCH_glEnd()

    print("[swift] LabGL ok")
  }
}
