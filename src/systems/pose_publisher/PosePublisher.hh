/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef GZ_SIM_SYSTEMS_POSEPUBLISHER_HH_
#define GZ_SIM_SYSTEMS_POSEPUBLISHER_HH_

#include <memory>
#include <gz/sim/System.hh>

namespace gz
{
namespace sim
{
// Inline to prevent multiple definitions
inline namespace GZ_SIM_VERSION_NAMESPACE {
namespace systems
{
  // Forward declaration of private data class
  class PosePublisherPrivate;

  /// \brief A system that publishes the poses of entities in the simulation.
  /// It can publish poses of links, models, visuals, collisions, and sensors.
  class PosePublisher :
    public System,
    public ISystemConfigure,
    public ISystemPostUpdate,
    public ISystemReset // <--- Added this interface
  {
    /// \brief Constructor
    public: PosePublisher();

    /// \brief Destructor
    public: ~PosePublisher() override;

    // Documentation inherited
    public: void Configure(const Entity &_entity,
                           const std::shared_ptr<const sdf::Element> &_sdf,
                           EntityComponentManager &_ecm,
                           EventManager &_eventMgr) override;

    // Documentation inherited
    public: void PostUpdate(const UpdateInfo &_info,
                            const EntityComponentManager &_ecm) override;

    /// \brief Reset the system to its initial state.
    /// \param[in] _info Update information.
    /// \param[in] _ecm The Entity Component Manager.
    // Documentation inherited
    public: void Reset(const UpdateInfo &_info,
                       EntityComponentManager &_ecm) override; // <--- Added this

    /// \brief Private data pointer
    private: std::unique_ptr<PosePublisherPrivate> dataPtr;
  };
}
}
}
}

#endif
