import LabGL

@main
struct LabGLExample
{
  static func main()
  {
    gl.viewport(x: 0, y: 0, width: 800, height: 600)
    
    gl.clearColor(red: 0.1, green: 0.1, blue: 0.15, alpha: 1.0)
    gl.clear(mask: UInt32(GL_COLOR_BUFFER_BIT))
    
    gl.enable(UInt32(GL_PBR_MODE))
    gl.material(face: UInt32(GL_FRONT_AND_BACK), pname: UInt32(GL_METALLIC),  param: 0.0)
    gl.material(face: UInt32(GL_FRONT_AND_BACK), pname: UInt32(GL_ROUGHNESS), param: 0.6)
    gl.material(face: UInt32(GL_FRONT_AND_BACK), pname: UInt32(GL_OCCLUSION), param: 1.0)
    
    lglSetIBLDiffuseSGs(0, nil)
    lglSetIBLSpecularSGs(0, nil)
    lglSetIBLReflectionCube(1, 0)

    gl.begin(mode: GL_TRIANGLES)
    gl.color(red: 1.0, green: 0.0, blue: 0.0); gl.vertex(x: -0.5,  y: -0.5)
    gl.color(red: 0.0, green: 1.0, blue: 0.0); gl.vertex(x:  0.5,  y: -0.5)
    gl.color(red: 0.0, green: 1.0, blue: 1.0); gl.vertex(x:  0.0,  y:  0.5)
    gl.end()

    print("[swift] LabGL ok")
  }
}
