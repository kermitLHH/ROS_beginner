/*
 * Copyright (c) 2009-2013, A. Hornung, University of Freiburg
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of Freiburg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


#include <ros/ros.h>
#include "OctomapServerMultilayer.h"

#define USAGE "\nUSAGE: octomap_server_multilayer <map.bt>\n" \
		"  map.bt: inital octomap 3D map file to read\n"

using namespace octomap_server;

int main(int argc, char** argv){
  ros::init(argc, argv, "octomap_server_multilayer");
  std::string mapFilename("");

  if (argc > 2 || (argc == 2 && std::string(argv[1]) == "-h")){
    ROS_ERROR("%s", USAGE);
    exit(-1);
  }


  OctomapServerMultilayer server;
  ros::spinOnce();

  if (argc == 2){
    mapFilename = std::string(argv[1]);
    if (!server.openFile(mapFilename)){
      ROS_ERROR("Could not open file %s", mapFilename.c_str());
      exit(1);
    }
  }




  try{
    ros::spin();
  }catch(std::runtime_error& e){
    ROS_ERROR("octomap_server_multilayer exception: %s", e.what());
    return -1;
  }

  return 0;
}
