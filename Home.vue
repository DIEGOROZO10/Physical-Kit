<template>
  <div class="view_container">
    <div class="subjects-container">
      <Subject
        class="subject"
        title="Mecanica"
        :experiments="getExperiments('Mecánica')"
      />
      <Subject
        class="subject"
        title="Magnetismo"
        :experiments="getExperiments('Magnetismo')"
      />
      <Subject
        class="subject"
        title="Electronica"
        :experiments="getExperiments('Electronica')"
      />
      <Subject
        class="subject"
        title="Ondas"
        :experiments="getExperiments('Ondas')"
      />
    </div>
  </div>
</template>

<script>
import Subject from "../components/Subject.vue";
import info from "../info";

export default {
  name: "Home",
  components: {
    Subject
  },
  methods: {
    getExperiments(name) {
      const subject = info.find(item => item.name === name);
      console.log(info[0].name);
      return subject ? subject.experiments : [];
    }
  }
};
</script>

<style>
.subject {
  width: 100%;
  height: 100%;
}
.subjects-container {
  display: grid;
  grid-template-columns: 50% 50%;
  grid-template-rows: 50% 50%;
  gap: 40px;
  justify-items: center;
  align-items: center;
}
</style>
